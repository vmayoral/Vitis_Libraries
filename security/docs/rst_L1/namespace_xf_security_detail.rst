.. index:: pair: namespace; detail
.. _doxid-namespacexf_1_1security_1_1detail:
.. _cid-xf::security::detail:

namespace detail
================

.. toctree::
	:hidden:



.. ref-code-block:: cpp
	:class: overview-code-block


.. FunctionSection




.. _doxid-namespacexf_1_1security_1_1detail_1a0a84cf846ca5c8b6b492b96c783bd346:
.. _cid-xf::security::detail::ff:

FF
--


FF overload (1)
+++++++++++++++


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int W,
	    int lW,
	    int hshW,
	    template< int iW, int ilW, int oW > class F
	    >
	void FF (
	    hls::stream <ap_uint <W>>& msgStrm,
	    ap_uint <lW> len,
	    hls::stream <ap_uint <hshW>>& hshStrm,
	    hls::stream <bool>& eHshStrm
	    )

compute hash value according to specific hash function and input data.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - W

        - the width of input stream msgStrm.

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - msgStrm

        - input stream.

    *
        - len

        - the length of input stream.

    *
        - hshStrm

        - output stream.

    *
        - eHshStrm

        - end flag of output stream hshStrm.

.. _doxid-namespacexf_1_1security_1_1detail_1aace9d294a5d49f536e97759b7e82be34:
.. _cid-xf::security::detail::ff-2:

FF overload (2)
+++++++++++++++


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int W,
	    int lW,
	    int hshW,
	    template< int iW, int ilW, int oW > class F
	    >
	ap_uint <hshW> FF (
	    ap_uint <W> msg,
	    hls::stream <ap_uint <hshW>>& hshStrm,
	    hls::stream <bool>& eHshStrm
	    )

compute hash value according to specific hash function and input data.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - W

        - the width of input message.

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - msg

        - input meassge.

    *
        - hshStrm

        - output stream.

    *
        - eHshStrm

        - end flag of output stream hshStrm.

.. _doxid-namespacexf_1_1security_1_1detail_1a4ee6d1360d1e9a71a6d3ee19be39e4bf:
.. _cid-xf::security::detail::hmacsqeunce:

hmacSqeunce
-----------


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int keyW,
	    int msgW,
	    int lW,
	    int hshW,
	    int blockSize,
	    template< int iW, int ilW, int oW > class F
	    >
	void hmacSqeunce (
	    hls::stream <ap_uint <keyW>>& keyStrm,
	    ap_uint <lW> keyLen,
	    hls::stream <ap_uint <msgW>>& msgStrm,
	    ap_uint <lW> msgLen,
	    hls::stream <ap_uint <hshW>>& hshStrm,
	    hls::stream <bool>& eHshStrm
	    )

compute hmac value according to specific hash function and input data in sequence.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyW

        - the width of input stream keyStrm.

    *
        - msgW

        - the width of input stream msgStrm.

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - blockSize

        - the block size(bytes) of the underlying hash function (e.g. 64 bytes for md5 and SHA-1).

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - keyStrm

        - input key stream.

    *
        - keyLen

        - the length of input key stream.

    *
        - msgStrm

        - input meassge stream.

    *
        - msgLen

        - the length of input message stream.

    *
        - hshStrm

        - output stream.

    *
        - eHshStrm

        - end flag of output stream hshStrm.

.. _doxid-namespacexf_1_1security_1_1detail_1a0028c6ad2fa86ce9cc86f0668c81db0d:
.. _cid-xf::security::detail::kpad:

kpad
----


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int keyW,
	    int lW,
	    int hshW,
	    int blockSize,
	    template< int iW, int ilW, int oW > class F
	    >
	void kpad (
	    hls::stream <ap_uint <keyW>>& keyStrm,
	    hls::stream <ap_uint <lW>>& keyLenStrm,
	    hls::stream <bool>& eLenStrm,
	    hls::stream <ap_uint <blockSize*8>>& kipadStrm,
	    hls::stream <ap_uint <blockSize*8>>& kopadStrm,
	    hls::stream <bool>& eLStrm
	    )

compute kipad and kopad after padding 0 on right and xor operation.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyW

        - the width of input stream keyStrm.

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - blockSize

        - the block size(bytes) of the underlying hash function (e.g. 64 bytes for md5 and SHA-1).

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - keyStrm

        - input key stream.

    *
        - keyLenStrm

        - the length stream of input key stream.

    *
        - eLenStrm

        - the end flag of length stream.

    *
        - kipadStrm

        - kipad stream.

    *
        - kopadStrm

        - kopad stream.

    *
        - eLStrm

        - end flag stream, which is a duplate of eLenStrm.

.. _doxid-namespacexf_1_1security_1_1detail_1ace578042046268d6e49ec16ca0842685:
.. _cid-xf::security::detail::hashkeymsg:

hashKeyMsg
----------


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int msgW,
	    int lW,
	    int hshW,
	    int blockSize,
	    template< int iW, int ilW, int oW > class F
	    >
	void hashKeyMsg (
	    hls::stream <ap_uint <blockSize*8>>& kipadStrm,
	    hls::stream <ap_uint <msgW>>& msgStrm,
	    hls::stream <ap_uint <lW>>& msgLenStrm,
	    hls::stream <bool>& eLenStrm,
	    hls::stream <ap_uint <hshW>>& mHshStrm,
	    hls::stream <bool>& eMHshStrm
	    )

compute hash(kipad and msg).



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - msgW

        - the width of input stream msgStrm.

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - blockSize

        - the block size(bytes) of the underlying hash function (e.g. 64 bytes for md5 and SHA-1).

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - kipadStrm

        - input kipad stream.

    *
        - msgStrm

        - input message stream.

    *
        - msgLenStrm

        - the length stream of input msg stream.

    *
        - eLenStrm

        - the end flag of length stream.

    *
        - mHshStrm

        - the hash value stream.

    *
        - eMHshStrm

        - the end flag of hash value stream.

.. _doxid-namespacexf_1_1security_1_1detail_1ab2855fd53bf834839364377309dd2846:
.. _cid-xf::security::detail::hashkopadhsh:

hashKopadHsh
------------


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int msgW,
	    int lW,
	    int hshW,
	    int blockSize,
	    template< int iW, int ilW, int oW > class F
	    >
	void hashKopadHsh (
	    hls::stream <ap_uint <blockSize*8>>& kopadStrm,
	    hls::stream <ap_uint <hshW>>& mHshStrm,
	    hls::stream <bool>& eMHshStrm,
	    hls::stream <ap_uint <hshW>>& hshStrm,
	    hls::stream <bool>& eHshStrm
	    )

compute hash(kopad and lastHash).



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - msgW

        - the width of input stream msgStrm.

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - blockSize

        - the block size(bytes) of the underlying hash function (e.g. 64 bytes for md5 and SHA-1).

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - kopadStrm

        - input kopad stream.

    *
        - mHshStrm

        - input last hash value stream.

    *
        - eMHshStrm

        - the end flag of mHshStrm.

    *
        - hshStrm

        - the hash value stream.

    *
        - eHshStrm

        - the end flag of hash value stream.

.. _doxid-namespacexf_1_1security_1_1detail_1ac27f3608a6791739489119f199d42097:
.. _cid-xf::security::detail::hmacsqeunce-2:

hmacSqeunce
-----------


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int keyW,
	    int msgW,
	    int lW,
	    int hshW,
	    int blockSize,
	    template< int iW, int ilW, int oW > class F
	    >
	void hmacSqeunce (
	    hls::stream <ap_uint <keyW>>& keyStrm,
	    hls::stream <ap_uint <lW>>& keyLenStrm,
	    hls::stream <ap_uint <msgW>>& msgStrm,
	    hls::stream <ap_uint <lW>>& msgLenStrm,
	    hls::stream <bool>& eLenStrm,
	    hls::stream <ap_uint <hshW>>& hshStrm,
	    hls::stream <bool>& eHshStrm
	    )

compute hmac value according to specific hash function and input data in sequence.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyW

        - the width of input stream keyStrm.

    *
        - msgW

        - the width of input stream msgStrm.

    *
        - blockSize

        - the block size(bytes) of the underlying hash function (e.g. 64 bytes for md5 and SHA-1).

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - keyStrm

        - input key stream.

    *
        - keyLenStrm

        - the length stream of input key stream.

    *
        - msgStrm

        - input meassge stream.

    *
        - msgLenStrm

        - the length stream of input message stream.

    *
        - eLenStrm

        - the end flag of length stream.

    *
        - hshStrm

        - output stream.

    *
        - eHshStrm

        - end flag of output stream hshStrm.

.. _doxid-namespacexf_1_1security_1_1detail_1a2d5ac73d0173563e73bd3efeb45f1d66:
.. _cid-xf::security::detail::hmacdataflow:

hmacDataflow
------------


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int keyW,
	    int msgW,
	    int lW,
	    int hshW,
	    int blockSize,
	    template< int iW, int ilW, int oW > class F
	    >
	void hmacDataflow (
	    hls::stream <ap_uint <keyW>>& keyStrm,
	    hls::stream <ap_uint <lW>>& keyLenStrm,
	    hls::stream <ap_uint <msgW>>& msgStrm,
	    hls::stream <ap_uint <lW>>& msgLenStrm,
	    hls::stream <bool>& eLenStrm,
	    hls::stream <ap_uint <hshW>>& hshStrm,
	    hls::stream <bool>& eHshStrm
	    )

compute hmac value according to specific hash function and input data in parallel.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyW

        - the width of input stream keyStrm.

    *
        - msgW

        - the width of input stream msgStrm.

    *
        - blockSize

        - the block size(bytes) of the underlying hash function (e.g. 64 bytes for md5 and SHA-1).

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - keyStrm

        - input key stream.

    *
        - keyLenStrm

        - the length stream of input key stream, in bytes not keyW-bit.

    *
        - msgStrm

        - input meassge stream.

    *
        - msgLenStrm

        - the length stream of input message stream, in bytes not msgW-bit.

    *
        - eLenStrm

        - the end flag of length stream.

    *
        - hshStrm

        - output stream.

    *
        - eHshStrm

        - end flag of output stream hshStrm.

.. _doxid-namespacexf_1_1security_1_1detail_1ab61bfd844b809f505330110f49fb484c:
.. _cid-xf::security::detail::hmacimp:

hmacImp
-------


.. code-block:: cpp
	
	#include "xf_security/hmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int keyW,
	    int msgW,
	    int lW,
	    int hshW,
	    int blockSize,
	    template< int iW, int ilW, int oW > class F
	    >
	void hmacImp (
	    hls::stream <ap_uint <keyW>>& keyStrm,
	    hls::stream <ap_uint <lW>>& keyLenStrm,
	    hls::stream <ap_uint <msgW>>& msgStrm,
	    hls::stream <ap_uint <lW>>& msgLenStrm,
	    hls::stream <bool>& eLenStrm,
	    hls::stream <ap_uint <hshW>>& hshStrm,
	    hls::stream <bool>& eHshStrm
	    )

compute hmac value according to specific hash function and input data.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyW

        - the width of input stream keyStrm.

    *
        - msgW

        - the width of input stream msgStrm.

    *
        - blockSize

        - the block size(bytes) of the underlying hash function (e.g. 64 bytes for md5 and SHA-1).

    *
        - hshW

        - the width of output stream hshStrm.

    *
        - F

        - hash function, iW is its input stream's width and oW is output stream's width.

    *
        - keyStrm

        - input key stream.

    *
        - keyLenStrm

        - the length stream of input key stream.

    *
        - msgStrm

        - input meassge stream.

    *
        - msgLenStrm

        - the length stream of input message stream.

    *
        - eLenStrm

        - the end flag of length stream.

    *
        - hshStrm

        - output stream.

    *
        - eHshStrm

        - end flag of output stream hshStrm.

