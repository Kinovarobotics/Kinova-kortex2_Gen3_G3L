'use strict';

var _interopRequireDefault = require('babel-runtime/helpers/interop-require-default')['default'];

Object.defineProperty(exports, '__esModule', {
  value: true
});

var _validator = require('validator');

/**
 * Returns true if the value is not empty
 *
 * @params {String} val
 * @returns {Boolean}
 */

var _validator2 = _interopRequireDefault(_validator);

_validator2['default'].extend('required', function (val) {
  return !_validator2['default'].isNull(val);
});

/**
 * Returns true if the value is boolean true
 *
 * @params {String} val
 * @returns {Boolean}
 */
_validator2['default'].extend('isChecked', function (val) {
  // compare it against string representation of a bool value, because
  // validator ensures all incoming values are coerced to strings
  // https://github.com/chriso/validator.js#strings-only
  return val === 'true';
});

exports['default'] = _validator2['default'];
module.exports = exports['default'];