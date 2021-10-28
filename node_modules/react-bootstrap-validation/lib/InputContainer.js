'use strict';

var _get = require('babel-runtime/helpers/get')['default'];

var _inherits = require('babel-runtime/helpers/inherits')['default'];

var _createClass = require('babel-runtime/helpers/create-class')['default'];

var _classCallCheck = require('babel-runtime/helpers/class-call-check')['default'];

var _interopRequireDefault = require('babel-runtime/helpers/interop-require-default')['default'];

Object.defineProperty(exports, '__esModule', {
    value: true
});

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var InputContainer = (function (_React$Component) {
    _inherits(InputContainer, _React$Component);

    function InputContainer() {
        _classCallCheck(this, InputContainer);

        _get(Object.getPrototypeOf(InputContainer.prototype), 'constructor', this).apply(this, arguments);
    }

    _createClass(InputContainer, [{
        key: 'componentWillMount',
        value: function componentWillMount() {
            this._inputs = {};
        }
    }, {
        key: 'componentWillUnmount',
        value: function componentWillUnmount() {}
    }, {
        key: 'registerInput',
        value: function registerInput(input) {
            var type = input.props.type;
            var name = input.props.name;

            if (!name) {
                throw new Error('Input ' + input + ' has no "name" prop');
            }

            if (type === 'radio') {
                this._inputs[name] = this._inputs[name] || [];
                this._inputs[name].push(input);
            } else {
                this._inputs[name] = input;
            }
        }
    }, {
        key: 'unregisterInput',
        value: function unregisterInput(input) {
            var type = input.props.type;
            var name = input.props.name;

            if (!name) {
                throw new Error('Input ' + input + ' has no "name" prop');
            }

            if (type === 'radio') {
                this._inputs[name] = this._inputs[name].filter(function (ipt) {
                    return ipt !== input;
                });
            } else {
                delete this._inputs[input.props.name];
            }
        }
    }]);

    return InputContainer;
})(_react2['default'].Component);

exports['default'] = InputContainer;
module.exports = exports['default'];