"use strict";

exports.__esModule = true;
exports.default = void 0;

var _contains = _interopRequireDefault(require("dom-helpers/contains"));

var _listen = _interopRequireDefault(require("dom-helpers/listen"));

var _ownerDocument = _interopRequireDefault(require("dom-helpers/ownerDocument"));

var _react = require("react");

var _useEventCallback = _interopRequireDefault(require("@restart/hooks/useEventCallback"));

var _warning = _interopRequireDefault(require("warning"));

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

const escapeKeyCode = 27;

const noop = () => {};

function isLeftClickEvent(event) {
  return event.button === 0;
}

function isModifiedEvent(event) {
  return !!(event.metaKey || event.altKey || event.ctrlKey || event.shiftKey);
}

const getRefTarget = ref => ref && ('current' in ref ? ref.current : ref);

/**
 * The `useRootClose` hook registers your callback on the document
 * when rendered. Powers the `<Overlay/>` component. This is used achieve modal
 * style behavior where your callback is triggered when the user tries to
 * interact with the rest of the document or hits the `esc` key.
 *
 * @param {Ref<HTMLElement>| HTMLElement} ref  The element boundary
 * @param {function} onRootClose
 * @param {object=}  options
 * @param {boolean=} options.disabled
 * @param {string=}  options.clickTrigger The DOM event name (click, mousedown, etc) to attach listeners on
 */
function useRootClose(ref, onRootClose, {
  disabled,
  clickTrigger = 'click'
} = {}) {
  const preventMouseRootCloseRef = (0, _react.useRef)(false);
  const onClose = onRootClose || noop;
  const handleMouseCapture = (0, _react.useCallback)(e => {
    const currentTarget = getRefTarget(ref);
    (0, _warning.default)(!!currentTarget, 'RootClose captured a close event but does not have a ref to compare it to. ' + 'useRootClose(), should be passed a ref that resolves to a DOM node');
    preventMouseRootCloseRef.current = !currentTarget || isModifiedEvent(e) || !isLeftClickEvent(e) || !!(0, _contains.default)(currentTarget, e.target);
  }, [ref]);
  const handleMouse = (0, _useEventCallback.default)(e => {
    if (!preventMouseRootCloseRef.current) {
      onClose(e);
    }
  });
  const handleKeyUp = (0, _useEventCallback.default)(e => {
    if (e.keyCode === escapeKeyCode) {
      onClose(e);
    }
  });
  (0, _react.useEffect)(() => {
    if (disabled || ref == null) return undefined; // Store the current event to avoid triggering handlers immediately
    // https://github.com/facebook/react/issues/20074

    let currentEvent = window.event;
    const doc = (0, _ownerDocument.default)(getRefTarget(ref)); // Use capture for this listener so it fires before React's listener, to
    // avoid false positives in the contains() check below if the target DOM
    // element is removed in the React mouse callback.

    const removeMouseCaptureListener = (0, _listen.default)(doc, clickTrigger, handleMouseCapture, true);
    const removeMouseListener = (0, _listen.default)(doc, clickTrigger, e => {
      // skip if this event is the same as the one running when we added the handlers
      if (e === currentEvent) {
        currentEvent = undefined;
        return;
      }

      handleMouse(e);
    });
    const removeKeyupListener = (0, _listen.default)(doc, 'keyup', e => {
      // skip if this event is the same as the one running when we added the handlers
      if (e === currentEvent) {
        currentEvent = undefined;
        return;
      }

      handleKeyUp(e);
    });
    let mobileSafariHackListeners = [];

    if ('ontouchstart' in doc.documentElement) {
      mobileSafariHackListeners = [].slice.call(doc.body.children).map(el => (0, _listen.default)(el, 'mousemove', noop));
    }

    return () => {
      removeMouseCaptureListener();
      removeMouseListener();
      removeKeyupListener();
      mobileSafariHackListeners.forEach(remove => remove());
    };
  }, [ref, disabled, clickTrigger, handleMouseCapture, handleMouse, handleKeyUp]);
}

var _default = useRootClose;
exports.default = _default;