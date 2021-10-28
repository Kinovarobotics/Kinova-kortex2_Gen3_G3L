# Installation
> `npm install --save @types/invariant`

# Summary
This package contains type definitions for invariant (https://github.com/zertosh/invariant).

# Details
Files were exported from https://github.com/DefinitelyTyped/DefinitelyTyped/tree/master/types/invariant.
## [index.d.ts](https://github.com/DefinitelyTyped/DefinitelyTyped/tree/master/types/invariant/index.d.ts)
````ts
// Type definitions for invariant 2.2
// Project: https://github.com/zertosh/invariant
// Definitions by: MichaelBennett <https://github.com/bennett000>
//                 dtinth <https://github.com/dtinth>
//                 Turadg Aleahmad <https://github.com/turadg>
// Definitions: https://github.com/DefinitelyTyped/DefinitelyTyped

declare let invariant: invariant.InvariantStatic;

export = invariant;
export as namespace invariant;

declare namespace invariant {
    interface InvariantStatic {
        (testValue: false, format: string, ...extra: any[]): never;
        (testValue: any, format: string, ...extra: any[]): asserts testValue;
    }
}

````

### Additional Details
 * Last updated: Thu, 26 Aug 2021 01:01:28 GMT
 * Dependencies: none
 * Global values: `invariant`

# Credits
These definitions were written by [MichaelBennett](https://github.com/bennett000), [dtinth](https://github.com/dtinth), and [Turadg Aleahmad](https://github.com/turadg).
