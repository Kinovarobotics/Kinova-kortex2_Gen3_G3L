'use strict';

Object.defineProperty(exports, '__esModule', {
    value: true
});
function iterate(files, cb) {
    Array.prototype.forEach.call(files, cb);
}

function getTotalFileSize(files) {
    var result = 0;

    iterate(files, function (file) {
        return result += file.size;
    });

    return result;
}

function getFileExtension(filename) {
    return filename.substr((~ -filename.lastIndexOf('.') >>> 0) + 2).toLowerCase();
}

var FileValidator = {
    extend: function extend(name, fn) {
        this[name] = fn;
    },

    /**
     * Returns `true` if there are no files in file list
     *
     * @param {FileList} files File list
     * @returns {Boolean}
     */
    isEmpty: function isEmpty(files) {
        return files.length === 0;
    },

    /**
     * Returns `true` if files count equals to 1
     *
     * @param {FileList} files File list
     * @returns {Boolean}
     */
    isSingle: function isSingle(files) {
        return files.length === 1;
    },

    /**
     * Returns `true` if files count is more than 1
     *
     * @param {FileList} files File list
     * @returns {Boolean}
     */
    isMultiple: function isMultiple(files) {
        return files.length > 1;
    },

    /**
     * Returns `true` if files count is within allowed range.
     * If `max` is not supplied, checks if files count equals `min`.
     *
     * @param {FileList} files File list
     * @param {Number} min Minimum files count
     * @param {Number} [max] Maximum files count
     * @returns {Boolean}
     */
    isFilesCount: function isFilesCount(files, min, max) {
        if (!max) {
            return files.length === min;
        } else {
            return files.length >= min && files.length <= max;
        }
    },

    /**
     * Returns `true` if total size of all files is within allowed range.
     *
     * @param {FileList} files File list
     * @param {Number} min Minimum size
     * @param {Number} [max] Maximum size
     * @returns {Boolean}
     */
    isTotalSize: function isTotalSize(files, min, max) {
        var totalSize = getTotalFileSize(files);

        return totalSize >= min && (!max || totalSize <= max);
    },

    /**
     * Returns `true` if each file's size is within allowed range
     *
     * @param {FileList} files File list
     * @param {Number} min Minimum size
     * @param {Number} [max] Maximum size
     * @returns {Boolean}
     */
    isEachFileSize: function isEachFileSize(files, min, max) {
        var allValid = true;

        iterate(files, function (file) {
            var fileValid = file.size >= min && (!max || file.size <= max);

            if (!fileValid) {
                allValid = false;
            }
        });

        return allValid;
    },

    /**
     * Returns `true` if each file's extension is in the `extensions` array
     *
     * @param {FileList} files File list
     * @param {Array} extensions Array of allowed file extensions. All extensions must be lower-case.
     * @returns {Boolean}
     */
    isExtension: function isExtension(files, extensions) {
        var allValid = true;

        iterate(files, function (file) {
            var ext = getFileExtension(file.name);

            if (extensions.indexOf(ext) === -1) {
                allValid = false;
            }
        });

        return allValid;
    },

    /**
     * Returns `true` if each file's mime type is in the `types` array
     *
     * @param {FileList} files File list
     * @param {Array} types Array of allowed mime types
     * @returns {Boolean}
     */
    isType: function isType(files, types) {
        var allValid = true;

        iterate(files, function (file) {
            if (types.indexOf(file.type) === -1) {
                allValid = false;
            }
        });

        return allValid;
    }
};

exports['default'] = FileValidator;
module.exports = exports['default'];