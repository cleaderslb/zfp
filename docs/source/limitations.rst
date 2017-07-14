.. include:: defs.rst

.. _limitations:

Limitations
===========

zfp is released as a beta version with the intent of giving people access
to the code and soliciting feedback on how to improve zfp for the first
full release.  As such, the zfp API is experimental and has not been
fixed, and it is entirely possible that future versions will employ a
different API or even a different codec.

Below is a list of known limitations and desirable features that may make
it into future versions of zfp.

- The current version of zfp allows for near lossless compression through
  suitable parameter choices, but no guarantees are made that bit-for-bit
  lossless compression is achieved.  We envision supporting lossless
  compression in a future version by compressing the difference between
  the original data and nearly losslessly compressed data.

- Special values like infinity and NaN are not supported.  Denormalized
  floating-point numbers are, however, correctly handled.  There is an
  implicit assumption that floating point conforms to IEEE, though
  extensions to other floating-point formats should be possible with
  minor effort.

- Although the current version of zfp supports iterators, pointers, and
  references to array elements, 'const' versions of these accessors are
  not yet available for read-only access.

- There currently is no way to make a complete copy of a compressed
  array, i.e. a = b; does not work for arrays a and b.  Copy constructors
  and assignment operators will be added in the near future.

- zfp can potentially provide higher precision than conventional float
  and double arrays, but the interface currently does not expose this.
  For example, such added precision could be useful in finite difference
  computations, where catastrophic cancellation can be an issue when
  insufficient precision is available.

- Only single and double precision types are supported.  Generalizations
  to IEEE half and quad precision would be useful.  For instance,
  compressed 64-bit-per-value storage of 128-bit quad-precision numbers
  could greatly improve the accuracy of double-precision floating-point
  computations using the same amount of storage.

- Complex-valued arrays are not directly supported.  Real and imaginary
  components must be stored as separate arrays, which may result in lost
  opportunities for compression, e.g. if the complex magnitude is constant
  and only the phase varies.

- zfp arrays are not thread-safe.  We are considering options for
  supporting multi-threaded access, e.g. for OpenMP parallelization.

- This version of zfp does not run on the GPU.  Some work has been done to
  port zfp to CUDA, and we expect to release such a version in the future.
