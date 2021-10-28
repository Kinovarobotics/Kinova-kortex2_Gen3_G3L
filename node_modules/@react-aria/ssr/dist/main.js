var _react2 = require("react");

var _react = $parcel$interopDefault(_react2);

var {
  useContext,
  useLayoutEffect,
  useMemo,
  useState
} = _react2;

function $parcel$interopDefault(a) {
  return a && a.__esModule ? a.default : a;
}

// Default context value to use in case there is no SSRProvider. This is fine for
// client-only apps. In order to support multiple copies of React Aria potentially
// being on the page at once, the prefix is set to a random number. SSRProvider
// will reset this to zero for consistency between server and client, so in the
// SSR case multiple copies of React Aria is not supported.
const $e873f27652f6cc1e1ee5ebcb9b5e51$var$defaultContext = {
  prefix: String(Math.round(Math.random() * 10000000000)),
  current: 0
};

const $e873f27652f6cc1e1ee5ebcb9b5e51$var$SSRContext = /*#__PURE__*/_react.createContext($e873f27652f6cc1e1ee5ebcb9b5e51$var$defaultContext);

/**
 * When using SSR with React Aria, applications must be wrapped in an SSRProvider.
 * This ensures that auto generated ids are consistent between the client and server.
 */
function SSRProvider(props) {
  let cur = useContext($e873f27652f6cc1e1ee5ebcb9b5e51$var$SSRContext);
  let value = useMemo(() => ({
    // If this is the first SSRProvider, start with an empty string prefix, otherwise
    // append and increment the counter.
    prefix: cur === $e873f27652f6cc1e1ee5ebcb9b5e51$var$defaultContext ? '' : cur.prefix + "-" + ++cur.current,
    current: 0
  }), [cur]);
  return /*#__PURE__*/_react.createElement($e873f27652f6cc1e1ee5ebcb9b5e51$var$SSRContext.Provider, {
    value: value
  }, props.children);
}

exports.SSRProvider = SSRProvider;
let $e873f27652f6cc1e1ee5ebcb9b5e51$var$canUseDOM = Boolean(typeof window !== 'undefined' && window.document && window.document.createElement);
/** @private */

function useSSRSafeId(defaultId) {
  let ctx = useContext($e873f27652f6cc1e1ee5ebcb9b5e51$var$SSRContext); // If we are rendering in a non-DOM environment, and there's no SSRProvider,
  // provide a warning to hint to the developer to add one.

  if (ctx === $e873f27652f6cc1e1ee5ebcb9b5e51$var$defaultContext && !$e873f27652f6cc1e1ee5ebcb9b5e51$var$canUseDOM) {
    console.warn('When server rendering, you must wrap your application in an <SSRProvider> to ensure consistent ids are generated between the client and server.');
  }

  return useMemo(() => defaultId || "react-aria" + ctx.prefix + "-" + ++ctx.current, [defaultId]);
}
/**
 * Returns whether the component is currently being server side rendered or
 * hydrated on the client. Can be used to delay browser-specific rendering
 * until after hydration.
 */


exports.useSSRSafeId = useSSRSafeId;

function useIsSSR() {
  let cur = useContext($e873f27652f6cc1e1ee5ebcb9b5e51$var$SSRContext);
  let isInSSRContext = cur !== $e873f27652f6cc1e1ee5ebcb9b5e51$var$defaultContext;
  let [isSSR, setIsSSR] = useState(isInSSRContext); // If on the client, and the component was initially server rendered,
  // then schedule a layout effect to update the component after hydration.

  if (typeof window !== 'undefined' && isInSSRContext) {
    // This if statement technically breaks the rules of hooks, but is safe
    // because the condition never changes after mounting.
    // eslint-disable-next-line react-hooks/rules-of-hooks
    useLayoutEffect(() => {
      setIsSSR(false);
    }, []);
  }

  return isSSR;
}

exports.useIsSSR = useIsSSR;
//# sourceMappingURL=main.js.map
