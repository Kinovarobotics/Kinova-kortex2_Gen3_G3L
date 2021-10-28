# Form validation for [react-bootstrap](http://react-bootstrap.github.io/).

Feedback, suggestions and pull-requests are welcome!

## Example 1: Simple Registration Form

```js
import React from 'react';
import { ButtonInput } from 'react-bootstrap';

// Import Form and ValidatedInput components. Notice that you need to use
// this ValidatedInput component instead of the original one to have
// validation and other features working
import { Form, ValidatedInput } from 'react-bootstrap-validation';

// There's also a wrapper for radio inputs that react-bootstrap
// doesn't (yet) have
import { Radio, RadioGroup } from 'react-bootstrap-validation';

class MyRegistrationForm extends React.Component {

    ...

    render() {
        return (
            <Form
                // Supply callbacks to both valid and invalid
                // submit attempts
                onValidSubmit={this._handleValidSubmit.bind(this)}
                onInvalidSubmit={this._handleInvalidSubmit.bind(this)}>

                <ValidatedInput
                    type='text'
                    label='Email'
                    // Each input that you need validated should have
                    // the "name" prop
                    name='email'
                    // Validation rules separated with comma
                    validate='required,isEmail'
                    // Error messages for each error type
                    errorHelp={{
                        required: 'Please enter your email',
                        isEmail: 'Email is invalid'
                    }}
                />

                <ValidatedInput
                    type='password'
                    name='password'
                    label='Password'
                    // You can pass params to validation rules
                    validate='required,isLength:6:60'
                    errorHelp={{
                        required: 'Please specify a password',
                        isLength: 'Password must be at least 6 characters'
                    }}
                />

                <ValidatedInput
                    type='password'
                    name='password-confirm'
                    label='Confirm Password'
                    // Validate can be a function as well
                    validate={(val, context) => val === context.password}
                    // If errorHelp property is a string, then it is used
                    // for all possible validation errors
                    errorHelp='Passwords do not match'
                />

                {/* Custom component to supply a couple of bootstrap
                    wrappers around radio inputs to look pretty */}
                <RadioGroup name='radio'
                            value='3'
                            label='Which one is better?'
                            // Supports validation as well
                            validate={v => v === 'cola'}
                            errorHelp='Pepsi? Seriously?'
                            // And accepts (almost) all the same props
                            // as other react-bootstrap components
                            labelClassName='col-xs-2'
                            wrapperClassName='col-xs-10'>
                    {/* Radio is a simple wrapper around react-bootstrap's
                        Input component */}
                    <Radio value='cola' label='Cola' />
                    <Radio value='pepsi' label='Pepsi' />
                </RadioGroup>

                <ValidatedInput
                    type='checkbox'
                    name='agree'
                    label='I agree to the terms and conditions'
                    // Validation rules is easily extendable to fit
                    // your needs. There are only two custom rules,
                    // 'isChecked' and 'required', others are stock
                    // validator.js methods
                    validate='isChecked'
                />

                <ButtonInput
                    type='submit'
                    bsSize='large'
                    bsStyle='primary'
                    value='Register'
                />
            </Form>
        );
    }

    _handleValidSubmit(values) {
        // Values is an object containing all values
        // from the inputs
    }

    _handleInvalidSubmit(errors, values) {
        // Errors is an array containing input names
        // that failed to validate
    }

    ...

}
```

## Example 2: Validating With Schema

In case you have an external validation schema, there are a couple of methods that allow you to use it. Consider the following example with [revalidator](https://github.com/flatiron/revalidator):

```js

...

import revalidator from 'revalidator';

// Simple revalidator schema with two fields
let schema = {
    properties: {
        email: {
            type: 'string',
            maxLength: 255,
            format: 'email',
            required: true,
            allowEmpty: false
        },
        password: {
            type: 'string',
            minLength: 8,
            maxLength: 60,
            required: true,
            allowEmpty: false
        }
    }
};

class MyLoginForm extends React.Component {

    ...

    render() {
        return (
            <Form
                // Provide a validation method for the whole
                // form values object. This way inputs will only
                // be validated upon submit.
                validateAll={this._validateForm.bind(this)}
                onValidSubmit={this._onSubmit.bind(this)}>

                <ValidatedInput type='text'
                       label='Email'
                       name='email'
                       errorHelp='Email address is invalid'/>

                <ValidatedInput type='password'
                       name='password'
                       label='Password'
                       errorHelp='Password is invalid'/>

                ...

            </Form>
        );
    }

    _validateForm(values) {
        let res = revalidator.validate(values, schema);

        // If the values passed validation, we return true
        if (res.valid) {
            return true;
        }

        // Otherwise we should return an object containing errors
        // e.g. { email: true, password: true }
        return res.errors.reduce((errors, error) => {
            // Set each property to either true or
            // a string error description
            errors[error.property] = true;

            return errors;
        }, {});
    }

    ...

}
```

## Components

### `Form`

Form is a wrapper around all the inputs.

**Properties**

##### `onValidSubmit: Function` **required**
Callback that receives `values` object, which is a hash map of `inputName => inputValue`.

```js
<Form onValidSubmit={values => alert(`Hello ${values.name}!`)}>
    <ValidatedInput name="name" />

    ...

</Form>
```

##### `onInvalidSubmit: Function`
Callback that is called when there was form submit event and form did not pass the validation. Receives two params: `errors: Array` and `values: Object`.

```js
<Form onValidSubmit={values => alert(`Hello ${values.name}!`)}
      onInvalidSubmit={(errors, values) => {
          alert(`Following fields are invalid: ${errors.join(', ')}`);
      }}>
    <ValidatedInput name="firstName" validate="required"/>
    <ValidatedInput name="lastName" validate="required"/>

    ...

</Form>
```

##### `model: Object`
Accepts a hash map of initial form values.

```js
<Form onValidSubmit={values => alert(`Hello ${values.name}!`)}
      model={{
          firstName: 'Jon',
          lastName: 'Snow'
      }}>
    <ValidatedInput name="firstName" validate="required"/>
    <ValidatedInput name="lastName" validate="required"/>

    ...

</Form>
```

##### `validateOne: Function`
If present, this callback is called when field needs to be revalidated -- either when form is submitted or input's `onChange` event is fired. Receives following arguments: `inputName: String`, `inputValue: String|Boolean|FileList` and `context: Object`. Result is expected in the same format as in the `ValidatedInput`'s `validate` callback. Useful for validation with external schema.
```js
function validateInput(name, value, context) {
    if (!SomeExternalSchema.validate(name, value, context)) {
        return '';
    }

    return true;
}

...

<Form onValidSubmit={this._onSubmit.bind(this)}
      validateOne={validateInput}>

      ...

</Form>
```

##### `validateAll: Function`
If present, this callback is called instead of field by field validation. Receives one argument: `values: Object`. Should return `true` if data is successfully validated, otherwise errors hash map of `fieldName => errorText`. If no specific error text is available, boolean `true` is allowed instead of string `errorText`.

```js
<Form onValidSubmit={this._onSubmit.bind(this)}
      validateAll={values => {
          // Force validation failure, return errors object.
          return {
              email: true,
              firstName: 'First name is invalid'
          };
      }}>

      ...

</Form>
```

##### `errorHelp: String|Object`
When validation error is triggered and there's no `errorHelp` property specified for the validated input, the error text is looked up in form's `errorHelp` property.

##### `validationEvent: String`
Input event that triggers field validation. Can be one of `onChange`, `onBlur` or `onFocus`. Default value is `onChange`.

### `ValidatedInput`

An extension of react-bootstrap's `Input` component. Should be used instead of the original one for all the fields that need to be validated. All `ValidatedInput`s should have `name` property defined.

**Properties**

##### `name: String` **required**
This property is inherited from `Input` with only difference that it is required for `ValidatedInput`.

##### `validationEvent: String`
Event that triggers validation. Can be one of `onChange`, `onBlur` or `onFocus`. Default value is `onChange`. Overrides Form's `validationEvent` property.

```js
<ValidatedInput
    name='email'
    validationEvent='onBlur'
    validate='required,isEmail'
/>
```

##### `validate: Function|String`
Either a validation function or a string validation rule.

Validation function receives two arguments, `val` and `context`. First one is the value of the input, second one is an object, containing values of all form fields. Having context is useful if you have a field, whose validation depends on other values of the form.
```js
<ValidatedInput
    name='passwordConfirm'
    validate={(val, context) => {
        return val === context.password;
    }}
/>
```
The result of the function should be either a boolean or a string. Any value returned that `!== true` is considered an error. If string is returned, it is used as an `errorHelp` property to render the error.

Validation rule is a combination of validator.js method names separated with comma.
```js
<ValidatedInput
    name='email'
    validate='required,isEmail,isLength:5:60'
/>
```
In the example above, input's value will be validated with three methods. `isLength` method also receives additional params. Inverse rules (like `!isNull`) are supported, although in `errorHelp` object they're looked up without the exclamation mark.

##### `errorHelp: Object|String`
Can be either a string with error text or an object with map `ruleName => errorText`.
```js
<ValidatedInput
    name="email"
    validate='required,isEmail',
    errorHelp={{
        required: 'Please enter your email',
        isEmail: 'Invalid email'
    }}
/>
```
If `errorHelp` property is omitted, default messages are looked up from `errorHelp` property of `Form` element.

### `Radio`
`Radio` component is basically the same as `ValidatedInput`, except it can not be validated. Validation is performed in the `RadioGroup`.

### `RadioGroup`
Wrapper component for `Radio` elements that performs validation and easy default value setup.

**Properties**

Following properties are inherited from original react-bootstrap `Input`:

`standalone, hasFeedback, bsSize, bsStyle, groupClassName, wrapperClassName, labelClassName`

And the next ones are from `ValidatedInput`:

`validate, errorHelp`

```js
<RadioGroup name='radio'
            // Set the initial value
            value='1'
            label='Some random options'
            labelClassName='col-xs-2'
            wrapperClassName='col-xs-10'>
    <Radio value='1' label='Option 1' />
    <Radio value='2' label='Option 2' />
    <Radio value='3' label='Option 3' />
</RadioGroup>
```

##### `validationEvent: String`
This property is a slightly different from `ValidatedInput`s one - it only accepts `onChange` (which is also it's default value) and should not be used.

## Validators

### `Validator`

A [validator.js](https://github.com/chriso/validator.js) object extended with the following custom validation methods:

##### `Validator.required(val: String)`
Returns `true` if the value is not null. Can be used as an alias to `!isNull` validation rule.

##### `Validator.isChecked(val: String)`
Used only for checkboxes as their value is return as `boolean` by the `Form` component. Returns `true` if the value equals to `'true'`. This is because all the values coming to validator.js methods are [treated as strings](https://github.com/chriso/validator.js#strings-only).

Refer to validator.js documentation for more information on it's validation methods and how to [extend it](https://github.com/chriso/validator.js#extensions).

### `FileValidator`

An object similar to the validator.js with `extend(name, func)` method and packed with file validation helpers. This validator is used for all `input[type=file]` in your form. Every validation method accepts [`FileList`](https://developer.mozilla.org/en/docs/Web/API/FileList) object as `files` param.

```js
import { FileValidator } from 'react-bootstrap-validation';

...

<ValidatedInput
    ref="file"
    name="file"
    type='file'
    label='Attachments'
    multiple
    validate={files => {
        if (FileValidator.isEmpty(files)) {
            return 'Please select a file';
        }

        if (!FileValidator.isFilesCount(files, 1, 3)) {
            return 'You can select not more than 3 files';
        }

        if (!FileValidator.isTotalSize(files, 1048576)) {
            return 'Total size must be at least 1MB';
        }

        if (!FileValidator.isEachFileSize(files, 0, 1048576)) {
            return 'Each file must not be larger than 1MB';
        }

        if (FileValidator.isExtension( files, [ 'exe', 'cmd', 'bat',
                'com', 'vbs', 'vbe', 'js', 'jse', 'wsf', 'wsh', 'msc' ])) {
            return 'Executable files are not allowed';
        }

        return true;
    }}
/>
```

Available methods:

##### `FileValidator.isEmpty(files: FileList)`
Returns `true` if there are no files in file list.

##### `FileValidator.isSingle(files: FileList)`
Returns `true` if files count equals to 1.

##### `FileValidator.isMultiple(files: FileList)`
Returns `true` if files count is more than 1.

##### `FileValidator.isFilesCount(files: FileList, min: Number, [max: Number])`
Returns `true` if files count is within allowed range. If `max` is not supplied, checks if files count equals `min`.

##### `FileValidator.isTotalSize(files: FileList, min: Number, [max: Number])`
Returns `true` if total size of all files is within allowed range.

##### `FileValidator.isEachFileSize(files: FileList, min: Number, [max: Number])`
Returns `true` if each file's size is within allowed range.

##### `FileValidator.isExtension(files: FileList, extensions: Array)`
Returns `true` if each file's extension is in the `extensions` array.

##### `FileValidator.isType(files: FileList, types: Array)`
Returns `true` if each file's mime type is in the `types` array.

## Tests

Not yet implemented.

## License (MIT)

```
The MIT License (MIT)

Copyright (c) 2015 Ivan Reshetnikov (keenn2007@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
