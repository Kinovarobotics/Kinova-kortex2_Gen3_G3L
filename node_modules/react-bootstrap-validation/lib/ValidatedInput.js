'use strict';

var _get = require('babel-runtime/helpers/get')['default'];

var _inherits = require('babel-runtime/helpers/inherits')['default'];

var _createClass = require('babel-runtime/helpers/create-class')['default'];

var _classCallCheck = require('babel-runtime/helpers/class-call-check')['default'];

var _Object$assign = require('babel-runtime/core-js/object/assign')['default'];

var _interopRequireDefault = require('babel-runtime/helpers/interop-require-default')['default'];

Object.defineProperty(exports, '__esModule', {
    value: true
});

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _reactBootstrap = require('react-bootstrap');

var ValidatedInput = (function (_Input) {
    _inherits(ValidatedInput, _Input);

    function ValidatedInput(props) {
        _classCallCheck(this, ValidatedInput);

        _get(Object.getPrototypeOf(ValidatedInput.prototype), 'constructor', this).call(this, props);

        if (!props._registerInput || !props._unregisterInput) {
            throw new Error('Input must be placed inside the Form component');
        }
    }

    _createClass(ValidatedInput, [{
        key: 'componentWillMount',
        value: function componentWillMount() {
            if (_reactBootstrap.Input.prototype.componentWillMount) {
                _get(Object.getPrototypeOf(ValidatedInput.prototype), 'componentWillMount', this).call(this);
            }

            this.props._registerInput(this);
        }
    }, {
        key: 'componentWillUnmount',
        value: function componentWillUnmount() {
            if (_reactBootstrap.Input.prototype.componentWillUnmount) {
                _get(Object.getPrototypeOf(ValidatedInput.prototype), 'componentWillUnmount', this).call(this);
            }

            this.props._unregisterInput(this);
        }
    }]);

    return ValidatedInput;
})(_reactBootstrap.Input);

exports['default'] = ValidatedInput;

ValidatedInput.propTypes = _Object$assign({}, _reactBootstrap.Input.propTypes, {
    name: _react2['default'].PropTypes.string.isRequired,
    validationEvent: _react2['default'].PropTypes.oneOf(['', 'onChange', 'onBlur', 'onFocus']),
    validate: _react2['default'].PropTypes.oneOfType([_react2['default'].PropTypes.func, _react2['default'].PropTypes.string]),
    errorHelp: _react2['default'].PropTypes.oneOfType([_react2['default'].PropTypes.string, _react2['default'].PropTypes.object])
});

ValidatedInput.defaultProps = _Object$assign({}, _reactBootstrap.Input.defaultProps, {
    validationEvent: ''
});
module.exports = exports['default'];