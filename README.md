# ed25519-donna-cofactored

The answer you actually want is either "Just use Ristretto" or
"Just use a more modern ed25519 implementation".  If at all possible
you should avoid using this package.

That said, every once in a while people still end up dusting off the
ed25519-donna code, so this fork attempts to provide a safer alternative,
by providing fixes to some of the more major issues in the codebase.

Fixes:

 * Verification (both single and batch) is now cofactored. As a
   consequence, this implementation will accept certain signatures
   that others will reject.  Note that non-cofactored batch verification
   is basically unsafe/unusable.

 * Verification now enforces S < L as mandated by RFC 8032 and FIPS 186-5.
   While the original ed25519 paper explicitly notes that signature
   malleability is out-of-scope, and as a consequence older implementations
   tend not to enforce this constraint, more modern definitions require
   it.

Out of scope:

 * Providing different behavior to upstream when verifying signatures
   with non-canonical/small-order A/R.  If precise behavior for those
   edge-cases matters to you then why are you using ed25519-donna in
   the first place?

### [ed25519-speccheck](https://github.com/novifinancial/ed25519-speccheck) output

```
 ---------------------------------------------------------------
|Library        | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11|
|---------------+---+---+---+---+---+---+---+---+---+---+---+---|
|upstream       | V | V | V | V | X | X | V | X | X | X | X | V |
|cofactored     | V | V | V | V | V | V | X | X | X | V | V | V |
 ---------------------------------------------------------------
```

### License

`ed25519-donna-cofactored-helpers.h` is under a 3-BSD license
due to it being a derived work.  Everything else, like the upstream
project, is Public Domain.
