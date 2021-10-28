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

var _ValidatedInput2 = require('./ValidatedInput');

var _ValidatedInput3 = _interopRequireDefault(_ValidatedInput2);

var Radio = (function (_ValidatedInput) {
    _inherits(Radio, _ValidatedInput);

    function Radio() {
        _classCallCheck(this, Radio);

        _get(Object.getPrototypeOf(Radio.prototype), 'constructor', this).apply(this, arguments);
    }

    _createClass(Radio, [{
        key: 'render',
        value: function render() {
            return _get(Object.getPrototypeOf(Radio.prototype), 'render', this).call(this);
        }
    }]);

    return Radio;
})(_ValidatedInput3['default']);

exports['default'] = Radio;

Radio.propTypes = _Object$assign({}, _ValidatedInput3['default'].propTypes, {
    name: _react2['default'].PropTypes.string
});
module.exports = exports['default'];