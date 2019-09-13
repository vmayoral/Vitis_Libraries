.. index:: pair: namespace; details
.. _doxid-namespacexf_1_1security_1_1details:
.. _cid-xf::security::details:

namespace details
=================

.. toctree::
	:hidden:

	struct_xf_security_details_SHA256Block.rst
	struct_xf_security_details_blockType.rst
	struct_xf_security_details_sha256_digest_config.rst
	struct_xf_security_details_sha256_digest_config-2.rst
	struct_xf_security_details_sha256_digest_config-3.rst
	class_xf_security_details_aesCbcDec.rst
	class_xf_security_details_aesCbcEnc.rst



.. _doxid-namespacexf_1_1security_1_1details_1a07222f2e1eeb318273a4b22a8c32b3dc:
.. _cid-xf::security::details::blocktypechacha:
.. _doxid-namespacexf_1_1security_1_1details_1a7032247284d6599cb53f45550d36267d:
.. _cid-xf::security::details::swap:
.. _doxid-namespacexf_1_1security_1_1details_1adf644fbe2feff7b136668d6627249dd2:
.. _cid-xf::security::details::extendeculid:
.. _doxid-namespacexf_1_1security_1_1details_1afe73c08199d1d29bcbaffeb20f8baed4:
.. _cid-xf::security::details::elementmuladd:
.. _doxid-namespacexf_1_1security_1_1details_1aa8557918854e0a8a3cacc7dccd801428:
.. _cid-xf::security::details::bigintmul:
.. _doxid-namespacexf_1_1security_1_1details_1ac56ac20af0073a15f820da68b7ea9b77:
.. _cid-xf::security::details::redc:
.. _doxid-namespacexf_1_1security_1_1details_1a61034df6ae150d9438dc5de666ab3f20:
.. _cid-xf::security::details::dupstrm:
.. _doxid-namespacexf_1_1security_1_1details_1a2ac7ab0c074c32d0c15646d16e6b0e40:
.. _cid-xf::security::details::ciphertext_gen:
.. _doxid-namespacexf_1_1security_1_1details_1a2fb785565b7d0a2ee757f9aed8aea7a3:
.. _cid-xf::security::details::plaintext_gen:
.. _doxid-namespacexf_1_1security_1_1details_1a789e24a5e1d927591e37f9b343bd5d8e:
.. _cid-xf::security::details::gf128_mult:
.. _doxid-namespacexf_1_1security_1_1details_1a4ca83180265cef498e7cde9026e01803:
.. _cid-xf::security::details::tag_gen:
.. _doxid-namespacexf_1_1security_1_1details_1af0cac68929f3e774d210efdc3a7abe7a:
.. _cid-xf::security::details::dup_strm:
.. _doxid-namespacexf_1_1security_1_1details_1af07f929189ad7b49b670e688681172b0:
.. _cid-xf::security::details::dup_strm-2:
.. _doxid-namespacexf_1_1security_1_1details_1aadc7ac5db009149af8e764ff3f81e8d2:
.. _cid-xf::security::details::generatemsgschedule:
.. _doxid-namespacexf_1_1security_1_1details_1af66f36cfce4e837f4046ca508e8860af:
.. _cid-xf::security::details::sha256_iter:
.. ref-code-block:: cpp
	:class: overview-code-block

	// typedefs

	typedef ap_uint <512> blockTypeChacha

	// structs

	struct :ref:`SHA256Block<doxid-structxf_1_1security_1_1details_1_1_s_h_a256_block>` 
	struct :ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>` 

	template <>
	struct :ref:`sha256_digest_config <true><doxid-structxf_1_1security_1_1details_1_1sha256__digest__config_3_01true_01_4>` 

	template <bool do_sha224>
	struct :ref:`sha256_digest_config<doxid-structxf_1_1security_1_1details_1_1sha256__digest__config>` 

	template <>
	struct :ref:`sha256_digest_config <false><doxid-structxf_1_1security_1_1details_1_1sha256__digest__config_3_01false_01_4>` 

	// classes

	template <unsigned int _keyWidth>
	class :ref:`aesCbcDec<doxid-classxf_1_1security_1_1details_1_1aes_cbc_dec>` 

	template <unsigned int _keyWidth>
	class :ref:`aesCbcEnc<doxid-classxf_1_1security_1_1details_1_1aes_cbc_enc>` 


.. FunctionSection




.. _doxid-namespacexf_1_1security_1_1details_1a8be2bcb760121d10c7c9245913cd6886:
.. _cid-xf::security::details::generateblock:

generateBlock
-------------


.. code-block:: cpp
	
	#include "xf_security/blake2b.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w = 64>
	void generateBlock (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <128>>& msg_len_strm,
	    hls::stream <ap_uint <w>>& key_strm,
	    hls::stream <ap_uint <8>>& key_len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <128>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <128>>& msg_len_out_strm,
	    hls::stream <ap_uint <8>>& key_len_out_strm
	    )

Generate 1024-bit processing blocks by padding (pipeline).

The algorithm reference is : "The BLAKE2 Cryptographic Hash and Message Authentication Code (MAC)". The optimization goal of this function is to yield a 1024-bit block per cycle.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - Bit width of the message words in block, default value is 64.

    *
        - msg_strm

        - The message being hashed.

    *
        - msg_len_strm

        - Message length in byte (0 <= msg_len <= 2^128).

    *
        - key_strm

        - The optional key.

    *
        - key_len_strm

        - Key length in byte (0 <= key_len <= 64).

    *
        - end_len_strm

        - The flag to signal end of input message stream.

    *
        - blk_strm

        - The 1024-bit hash block.

    *
        - nblk_strm

        - The number of hash block for this message.

    *
        - end_nblk_strm

        - End flag for number of hash block.

    *
        - msg_len_out_strm

        - Message length pass on to the digest process.

    *
        - key_len_out_strm

        - Key length pass on to the digest process.

.. _doxid-namespacexf_1_1security_1_1details_1af9bf62640e08b903458c6249619c819b:
.. _cid-xf::security::details::rotr:

ROTR
----


.. code-block:: cpp
	
	#include "xf_security/blake2b.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int w = 64,
	    unsigned int n = 0
	    >
	ap_uint <w> ROTR (ap_uint <w> x)

The implementation of rotate right (circular right shift) operation.

The algorithm reference is : "The BLAKE2 Cryptographic Hash and Message Authentication Code (MAC)".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - n

        - Number of bits for input x to be shifted.

    *
        - x

        - Word to be rotated.

.. _doxid-namespacexf_1_1security_1_1details_1ac56ea1e43d2c767528dd1cd7e3212147:
.. _cid-xf::security::details::g:

G
-


.. code-block:: cpp
	
	#include "xf_security/blake2b.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w = 64>
	void G (
	    ap_uint <w> v [16],
	    ap_uint <4> a,
	    ap_uint <4> b,
	    ap_uint <4> c,
	    ap_uint <4> d,
	    ap_uint <w> x,
	    ap_uint <w> y
	    )

Mixing function G as defined in standard.

The algorithm reference is : "The BLAKE2 Cryptographic Hash and Message Authentication Code (MAC)".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Bit

        - width of the words, default value is 64.

    *
        - v

        - Working vector.

    *
        - a

        - The first index.

    *
        - b

        - The second index.

    *
        - c

        - The third index.

    *
        - d

        - the fourth index.

    *
        - x

        - The first input working word.

    *
        - y

        - The second input working word.

.. _doxid-namespacexf_1_1security_1_1details_1a5f34b33efe5aa6ae657dde4879c9396b:
.. _cid-xf::security::details::halfmixing:

halfMixing
----------


.. code-block:: cpp
	
	#include "xf_security/blake2b.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w = 64>
	void halfMixing (
	    ap_uint <w> v [16],
	    ap_uint <4> vi0,
	    ap_uint <4> vi1,
	    ap_uint <4> vi2,
	    ap_uint <4> vi3,
	    ap_uint <4> vi4,
	    ap_uint <4> vi5,
	    ap_uint <4> vi6,
	    ap_uint <4> vi7,
	    ap_uint <4> vi8,
	    ap_uint <4> vi9,
	    ap_uint <4> vi10,
	    ap_uint <4> vi11,
	    ap_uint <4> vi12,
	    ap_uint <4> vi13,
	    ap_uint <4> vi14,
	    ap_uint <4> vi15,
	    ap_uint <w> m [16],
	    ap_uint <4> mi0,
	    ap_uint <4> mi1,
	    ap_uint <4> mi2,
	    ap_uint <4> mi3,
	    ap_uint <4> mi4,
	    ap_uint <4> mi5,
	    ap_uint <4> mi6,
	    ap_uint <4> mi7
	    )

Mixing 2 halves for unroll purpose.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Bit

        - width of the words, default value is 64.

    *
        - v

        - Working vector.

    *
        - vi0

        - The 1st index for working vector.

    *
        - vi1

        - The 2nd index for working vector.

    *
        - vi2

        - The 3rd index for working vector.

    *
        - vi3

        - The 4th index for working vector.

    *
        - vi4

        - The 5th index for working vector.

    *
        - vi5

        - The 6th index for working vector.

    *
        - vi6

        - The 7th index for working vector.

    *
        - vi7

        - The 8th index for working vector.

    *
        - vi8

        - The 9th index for working vector.

    *
        - vi9

        - The 10th index for working vector.

    *
        - vi10

        - The 11th index for working vector.

    *
        - vi11

        - The 12th index for working vector.

    *
        - vi12

        - The 13th index for working vector.

    *
        - vi13

        - The 14th index for working vector.

    *
        - vi14

        - The 15th index for working vector.

    *
        - vi15

        - The 16th index for working vector.

    *
        - y

        - Message vector.

    *
        - mi0

        - The 1st index for message vector.

    *
        - mi1

        - The 2nd index for message vector.

    *
        - mi2

        - The 3rd index for message vector.

    *
        - mi3

        - The 4th index for message vector.

    *
        - mi4

        - The 5th index for message vector.

    *
        - mi5

        - The 6th index for message vector.

    *
        - mi6

        - The 7th index for message vector.

    *
        - mi7

        - The 8th index for message vector.

.. _doxid-namespacexf_1_1security_1_1details_1ac308d30cef1463409f9f72d078f55c1e:
.. _cid-xf::security::details::compress:

Compress
--------


.. code-block:: cpp
	
	#include "xf_security/blake2b.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int w = 64,
	    unsigned int round = 12
	    >
	void Compress (
	    ap_uint <w> h [8],
	    ap_uint <w> blake2b_iv [8],
	    ap_uint <w> m [16],
	    ap_uint <2*w> t,
	    bool last
	    )

Compression function F as defined in standard.

The optimization goal of this function is for better performance. The algorithm reference is : "The BLAKE2 Cryptographic Hash and Message Authentication Code (MAC)".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - Bit width of the words, default value is 64.

    *
        - round

        - Number of rounds, 12 for BLAKE2b and 10 for BLAKE2s.

    *
        - h

        - State vector.

    *
        - blake2b_iv

        - Initialization vector.

    *
        - m

        - Message block vector.

    *
        - t

        - Offset counter.

    *
        - last

        - Final block indicator.

.. _doxid-namespacexf_1_1security_1_1details_1ad362b9b1b268f268c869fa907ffa19f9:
.. _cid-xf::security::details::blake2bdigest:

blake2bDigest
-------------


.. code-block:: cpp
	
	#include "xf_security/blake2b.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void blake2bDigest (
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <128>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <8>>& key_len_strm,
	    hls::stream <ap_uint <128>>& msg_len_strm,
	    hls::stream <ap_uint <8>>& out_len_strm,
	    hls::stream <ap_uint <8*w>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

The implementation of the digest prcoess of BLAKE2.

The algorithm reference is : "The BLAKE2 Cryptographic Hash and Message Authentication Code (MAC)". The optimization goal of this function is for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - Bit width of the words, default value is 64.

    *
        - blk_strm

        - The 512-bit hash block.

    *
        - nblk_strm

        - The number of hash block for this message.

    *
        - end_nblk_strm

        - End flag for number of hash block.

    *
        - key_len_strm

        - Key length in byte (0 <= key_len <= 64).

    *
        - msg_len_strm

        - Message length in byte (0 <= msg_len <= 2^128).

    *
        - out_len_strm

        - Result hash value length in byte (0 < out_len < 64).

    *
        - digest_strm

        - The full digest stream (result is stored in the lower out_len bytes).

    *
        - end_digest_strm

        - Flag to signal the end of the result.

.. _doxid-namespacexf_1_1security_1_1details_1acd9e497ba44d2fcd6155391336e8e64e:
.. _cid-xf::security::details::aescbcencrypt:

aesCbcEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCbcEncrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& initialization_vector,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e
	    )

aesCbcEncrypt is CBC encryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - initialization_vector

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertext

        - Output encrypted block stream text, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a7b5da858c0d8139e0264c6b1e3958e09:
.. _cid-xf::security::details::aescbcdecrypt:

aesCbcDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCbcDecrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& IV_strm,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e
	    )

aesCbcDecrypt is CBC decryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - initialization_vector

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintext

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a0fdf7464d2112a88ceeebafe6ea8e578:
.. _cid-xf::security::details::formatting:

formatting
----------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8
	    >
	void formatting (
	    hls::stream <ap_uint <128>>& ADStrm,
	    hls::stream <ap_uint <8* (15-_q)>>& nonceStrm,
	    hls::stream <ap_uint <64>>& lenADStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <bool>& endLenStrm,
	    hls::stream <ap_uint <128>>& blockStrm,
	    hls::stream <ap_uint <64>>& outLenADStrm,
	    hls::stream <ap_uint <8* (15-_q)>>& outNonceStrm
	    )

Impletmentation of formatting function as specified in standard.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _t

        - Length of the MAC in byte, t is an element of {4, 6, 8, 10, 12, 14, 16}.

    *
        - _q

        - Length in byte of the binary representation of the length of the payload in byte, q is an element of {2, 3, 4, 5, 6, 7, 8}.

    *
        - ADStrm

        - Associated data stream.

    *
        - nonceStrm

        - The nonce stream.

    *
        - lenADStrm

        - Length of associated data in byte.

    *
        - lenPldStrm

        - Length of payload in byte.

    *
        - endLenStrm

        - Flag to signal the end of the length streams.

    *
        - blockStrm

        - Block stream of the formatted input as specified in reference.

    *
        - outLenADStrm

        - Pass on the length of associated data to CBC-MAC.

    *
        - outNonceStrm

        - Pass on the nonce to CTR.

.. _doxid-namespacexf_1_1security_1_1details_1ae25f842c4fac08ac46ae09b34cb52f80:
.. _cid-xf::security::details::aesctrencrypt:

aesCtrEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _q = 8,
	    unsigned int _keyWidth = 256
	    >
	void aesCtrEncrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <_keyWidth>>& cipherkeyStrm,
	    hls::stream <ap_uint <8* (15-_q)>>& nonceStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <bool>& endLenPldStrm,
	    hls::stream <ap_uint <128>>& outPayloadStrm,
	    hls::stream <ap_uint <_keyWidth>>& outCipherkeyStrm,
	    hls::stream <ap_uint <128>>& S0Strm,
	    hls::stream <ap_uint <128>>& cipherStrm,
	    hls::stream <ap_uint <64>>& lenCphStrm
	    )

Implementation of CTR encryption part in CCM.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _q

        - Length in byte of the binary representation of the length of the payload in byte, q is an element of {2, 3, 4, 5, 6, 7, 8}.

    *
        - _keyWidth

        - Bit-width of the cipher key, typically 128, 192, or 256 for AES.

    *
        - payloadStrm

        - Input block stream text to be encrypted.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption.

    *
        - nonceStrm

        - The nonce stream.

    *
        - lenPldStrm

        - Length of payload in byte.

    *
        - endLenPldStrm

        - Flag to signal the end of the payload length stream.

    *
        - outPayloadStrm

        - Pass on the payload stream to CBC-MAC.

    *
        - outCipherkeyStrm

        - Pass on the cipherkey to CBC-MAC.

    *
        - S0Strm

        - First cipher used to generate the MAC.

    *
        - cipherStrm

        - Output encrypted block stream text.

    *
        - lenCphStrm

        - Length of cipher in byte.

.. _doxid-namespacexf_1_1security_1_1details_1a016713797b99badb9b9432a40ec99c0d:
.. _cid-xf::security::details::aesctrdecrypt:

aesCtrDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _q = 8,
	    unsigned int _keyWidth = 256
	    >
	void aesCtrDecrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <_keyWidth>>& cipherkeyStrm,
	    hls::stream <ap_uint <8* (15-_q)>>& nonceStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <bool>& endLenPldStrm,
	    hls::stream <ap_uint <128>>& outPayloadStrm,
	    hls::stream <ap_uint <_keyWidth>>& outCipherkeyStrm,
	    hls::stream <ap_uint <128>>& S0Strm,
	    hls::stream <ap_uint <128>>& cipherStrm,
	    hls::stream <ap_uint <64>>& lenCphStrm
	    )

Implementation of CTR decryption part in CCM.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _q

        - Length in byte of the binary representation of the length of the payload in byte, q is an element of {2, 3, 4, 5, 6, 7, 8}.

    *
        - _keyWidth

        - Bit-width of the cipher key, typically 128, 192, or 256 for AES.

    *
        - payloadStrm

        - Input block stream text to be decrypted.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption.

    *
        - nonceStrm

        - The nonce stream.

    *
        - lenPldStrm

        - Length of payload in byte.

    *
        - endLenPldStrm

        - Flag to signal the end of the payload length stream.

    *
        - outPayloadStrm

        - Pass on the payload stream to CBC-MAC.

    *
        - outCipherkeyStrm

        - Pass on the cipherkey to CBC-MAC.

    *
        - S0Strm

        - First cipher used to generate the MAC.

    *
        - cipherStrm

        - Output decrypted block stream text.

    *
        - lenCphStrm

        - Length of cipher in byte.

.. _doxid-namespacexf_1_1security_1_1details_1af1d768278ab714ff7283448275a71156:
.. _cid-xf::security::details::cbc_mac:

CBC_MAC
-------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _keyWidth = 256
	    >
	void CBC_MAC (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <64>>& lenADStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <ap_uint <128>>& blockStrm,
	    hls::stream <ap_uint <_keyWidth>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& S0Strm,
	    hls::stream <bool>& endLenStrm,
	    hls::stream <ap_uint <8*_t>>& tagStrm,
	    hls::stream <bool>& endTagStrm
	    )

Impletmentation of CBC-MAC in CCM.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _t

        - Length of the MAC in byte, t is an element of {4, 6, 8, 10, 12, 14, 16}.

    *
        - _keyWidth

        - Bit-width of the cipher key, typically 128, 192, or 256 for AES.

    *
        - payloadStrm

        - Input block stream text.

    *
        - lenADStrm

        - Length of associated data in byte.

    *
        - lenPldStrm

        - Length of payload in byte.

    *
        - blockStrm

        - Block stream of the formatted input as specified in reference.

    *
        - cipherkeyStrm

        - Input cipher key, typically 128, 192, or 256 for AES.

    *
        - S0Strm

        - First cipher used to generate the MAC.

    *
        - endLenStrm

        - Flag to signal the end of the length streams.

    *
        - tagStrm

        - The MAC.

    *
        - endTagStrm

        - Flag to signal the end of the MAC stream.

.. _doxid-namespacexf_1_1security_1_1details_1a88f49bebbe401cc73a6b42570c30bc8c:
.. _cid-xf::security::details::aesccmencrypt:

aesCcmEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8,
	    unsigned int _keyWidth = 256
	    >
	void aesCcmEncrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <_keyWidth>>& cipherkeyStrm,
	    hls::stream <ap_uint <8* (15-_q)>>& nonceStrm,
	    hls::stream <ap_uint <128>>& ADStrm,
	    hls::stream <ap_uint <64>>& lenADStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <bool>& endLenStrm,
	    hls::stream <ap_uint <128>>& cipherStrm,
	    hls::stream <ap_uint <64>>& lenCphStrm,
	    hls::stream <ap_uint <8*_t>>& tagStrm,
	    hls::stream <bool>& endTagStrm
	    )

aesCcmEncrypt is CCM encryption mode with AES single block cipher.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _t

        - Length of the MAC in byte, t is an element of {4, 6, 8, 10, 12, 14, 16}.

    *
        - _q

        - Length in byte of the binary representation of the length of the payload in byte, q is an element of {2, 3, 4, 5, 6, 7, 8}.

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - payloadStrm

        - Input block stream text to be encrypted.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption.

    *
        - nonceStrm

        - The nonce stream.

    *
        - ADStrm

        - Associated data stream.

    *
        - lenADStrm

        - Length of associated data in byte.

    *
        - lenPldStrm

        - Length of payload in byte.

    *
        - endLenStrm

        - Flag to signal the end of the length streams.

    *
        - cipherStrm

        - Output encrypted block stream text.

    *
        - lenCphStrm

        - Length of cipher in byte.

    *
        - tagStrm

        - The MAC stream.

    *
        - endTagStrm

        - Flag to signal the end of the MAC stream.

.. _doxid-namespacexf_1_1security_1_1details_1a7896c0e187cddeecf323260383ebe704:
.. _cid-xf::security::details::aesccmdecrypt:

aesCcmDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8,
	    unsigned int _keyWidth = 256
	    >
	void aesCcmDecrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <_keyWidth>>& cipherkeyStrm,
	    hls::stream <ap_uint <8* (15-_q)>>& nonceStrm,
	    hls::stream <ap_uint <128>>& ADStrm,
	    hls::stream <ap_uint <64>>& lenADStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <bool>& endLenStrm,
	    hls::stream <ap_uint <128>>& cipherStrm,
	    hls::stream <ap_uint <64>>& lenCphStrm,
	    hls::stream <ap_uint <8*_t>>& tagStrm,
	    hls::stream <bool>& endTagStrm
	    )

aesCcmDecrypt is CCM decryption mode with AES single block cipher.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _t

        - Length of the MAC in byte, t is an element of {4, 6, 8, 10, 12, 14, 16}.

    *
        - _q

        - Length in byte of the binary representation of the length of the payload in byte, q is an element of {2, 3, 4, 5, 6, 7, 8}.

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - payloadStrm

        - Input block stream text to be decrypted.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption.

    *
        - nonceStrm

        - The nonce stream.

    *
        - ADStrm

        - Associated data stream.

    *
        - lenADStrm

        - Length of associated data in byte.

    *
        - lenPldStrm

        - Length of payload in byte.

    *
        - endLenStrm

        - Flag to signal the end of the length streams.

    *
        - cipherStrm

        - Output decrypted block stream text.

    *
        - lenCphStrm

        - Length of cipher in byte.

    *
        - tagStrm

        - The MAC stream.

    *
        - endTagStrm

        - Flag to signal the end of the MAC stream.

.. _doxid-namespacexf_1_1security_1_1details_1a3c3cf684300ca636dd40aabe8ddb1412:
.. _cid-xf::security::details::aescfb1encrypt:

aesCfb1Encrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCfb1Encrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& initialization_vector,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e
	    )

aesCfb1Encrypt is CFB1 encryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - initialization_vector

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertext

        - Output encrypted block stream text, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a551420cf3d3a1f6cac06ef3f34d8ed80:
.. _cid-xf::security::details::aescfb1decrypt:

aesCfb1Decrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCfb1Decrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& IV_strm,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e
	    )

aesCfb1Decrypt is CFB1 decryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - IV_strm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintext

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e

        - End flag of stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a195f42f9320e96043d277575bbbafc16:
.. _cid-xf::security::details::aescfb8encrypt:

aesCfb8Encrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCfb8Encrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& initialization_vector,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e
	    )

aesCfb8Encrypt is CFB8 encryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - initialization_vector

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertext

        - Output encrypted block stream text, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a09dd351257531100a67d8d7ea0f9291b:
.. _cid-xf::security::details::aescfb8decrypt:

aesCfb8Decrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth>
	void aesCfb8Decrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& IV_strm,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e
	    )

aesCfb8Decrypt is CFB8 decryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - IV_strm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintext

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e

        - End flag of stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a35e8f3407d053b1b6c02c035dd8c42b4:
.. _cid-xf::security::details::aescfb128encrypt:

aesCfb128Encrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCfb128Encrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& initialization_vector,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e
	    )

aesCfb128Encrypt is CFB128 encryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - initialization_vector

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertext

        - Output encrypted block stream text, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1aedeed8606323e776e455a276b7ce6a04:
.. _cid-xf::security::details::aescfb128decrypt:

aesCfb128Decrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCfb128Decrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& IV_strm,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e
	    )

aesCfb128Decrypt is CFB128 decryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - IV_strm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintext

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e

        - End flag of stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1ac3c594a08d3625a5547c750ccc928c7b:
.. _cid-xf::security::details::chachaencrpt:

chachaEncrpt
------------


.. code-block:: cpp
	
	#include "xf_security/chacha20.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void chachaEncrpt (
	    hls::stream <:ref:`blockTypeChacha<doxid-namespacexf_1_1security_1_1details_1a07222f2e1eeb318273a4b22a8c32b3dc>`>& stateStrm,
	    hls::stream <:ref:`blockTypeChacha<doxid-namespacexf_1_1security_1_1details_1a07222f2e1eeb318273a4b22a8c32b3dc>`>& packPlainStrm,
	    hls::stream <ap_uint <8>>& numPackPlainStrm,
	    hls::stream <bool>& ePackPlainStrm,
	    hls::stream <:ref:`blockTypeChacha<doxid-namespacexf_1_1security_1_1details_1a07222f2e1eeb318273a4b22a8c32b3dc>`>& packCipherStrm,
	    hls::stream <ap_uint <8>>& numPackCipherStrm,
	    hls::stream <bool>& ePackCipherStrm
	    )

chachaEncrpt encrpyts the plain text.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - stateStrm

        - input state stream only once

    *
        - packPlainStrm

        - input plain text stream

    *
        - numPackPlainStrm

        - the number of effective bytes in each packed data

    *
        - ePackPlainStrm

        - the end flag of packPlainStrm

    *
        - packCipherStrm

        - output cipher stream

    *
        - numPackCipherStrm

        - the number of effective bytes in each packed data

    *
        - ePackCipherStrm

        - the end flag of packCipherStrm

.. _doxid-namespacexf_1_1security_1_1details_1ae0a3595212924936fc38a59b16eaec43:
.. _cid-xf::security::details::generateblock-2:

generateBlock
-------------


.. code-block:: cpp
	
	#include "xf_security/chacha20.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void generateBlock (
	    hls::stream <ap_uint <256>>& keyStrm,
	    hls::stream <ap_uint <128>>& counterNonceStrm,
	    hls::stream <:ref:`blockTypeChacha<doxid-namespacexf_1_1security_1_1details_1a07222f2e1eeb318273a4b22a8c32b3dc>`>& stateStrm
	    )

generateBlock generates the state matrix from initial key and counter. state matrix: s[0] s[1] s[2] s[3] s[4] s[5] s[6] s[7] s[8] s[9] s[10] s[11] s[12] s[13] s[14] s[15]

the layout of the data from counteStrm 0-31 bit: counter s[12] 32-63 bit: nonce1 s[13] 64-95 bit: nonce2 s[14] 96-127 bit: nonce3 s[15]



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyStrm

        - initial key

    *
        - counterNonceStm

        - initial counter and nonce

    *
        - stateStrm

        - output state stream

.. _doxid-namespacexf_1_1security_1_1details_1a21342d4b6c28b0ee8b541b430c89ed34:
.. _cid-xf::security::details::packmsg:

packMsg
-------


.. code-block:: cpp
	
	#include "xf_security/chacha20.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void packMsg (
	    hls::stream <ap_uint <8>>& plainStrm,
	    hls::stream <bool>& ePlainStrm,
	    hls::stream <:ref:`blockTypeChacha<doxid-namespacexf_1_1security_1_1details_1a07222f2e1eeb318273a4b22a8c32b3dc>`>& packPlainStrm,
	    hls::stream <ap_uint <8>>& numPackPlainStrm,
	    hls::stream <bool>& ePackPlainStrm
	    )

packMsg converts a few of bytes to a big width data.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plainStrm

        - input stream with byte

    *
        - ePlainStrm

        - end of plainStrm

    *
        - packPlainStrm

        - output big width stream

    *
        - numPackPlainStrm

        - the number of effective bytes in each packed data

    *
        - ePackPlainStrm

        - the end flag of packPlainStrm

.. _doxid-namespacexf_1_1security_1_1details_1a1c2da864d10e25d1bfcf7a64195fca09:
.. _cid-xf::security::details::convert2byte:

convert2Byte
------------


.. code-block:: cpp
	
	#include "xf_security/chacha20.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void convert2Byte (
	    hls::stream <:ref:`blockTypeChacha<doxid-namespacexf_1_1security_1_1details_1a07222f2e1eeb318273a4b22a8c32b3dc>`>& packStrm,
	    hls::stream <ap_uint <8>>& numPackStrm,
	    hls::stream <bool>& ePackStrm,
	    hls::stream <ap_uint <8>>& byteStrm,
	    hls::stream <bool>& eByteStrm
	    )

convert2Byte converts big width data to a few of bytes.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - packStrm

        - a big width stream

    *
        - numPackStrm

        - each element contains the number of effective bytes

    *
        - ePackStrm

        - the end flag of packStrm

    *
        - byteStrm

        - output byte stream

    *
        - eByteStrm

        - the end flag of byteStrm

.. _doxid-namespacexf_1_1security_1_1details_1a3f1951467a9ff46a223c77ccc80b31d9:
.. _cid-xf::security::details::chacha20imp:

chacha20Imp
-----------


.. code-block:: cpp
	
	#include "xf_security/chacha20.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void chacha20Imp (
	    hls::stream <ap_uint <256>>& keyStrm,
	    hls::stream <ap_uint <128>>& counterNonceStrm,
	    hls::stream <ap_uint <8>>& plainStrm,
	    hls::stream <bool>& ePlainStrm,
	    hls::stream <ap_uint <8>>& cipherStrm,
	    hls::stream <bool>& eCipherStrm
	    )

chacha20 is a function for stream ciphering



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyStrm

        - initail key

    *
        - counterNonceStm

        - initial counter and nonce

    *
        - plainStrm

        - input plain text to be encrypted

    *
        - ePlainStrm

        - the end flag of plainStrm

    *
        - cipherStrm

        - output encrypted text

    *
        - eCipherStrm

        - the end flag of cipherStrm

.. _doxid-namespacexf_1_1security_1_1details_1ae07ad3b9e18d8749754e7b1914711c21:
.. _cid-xf::security::details::aesctrencrypt-2:

aesCtrEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCtrEncrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& initialization_vector,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e
	    )

aesCtrEncrypt is CTR encryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - initialization_vector

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertext

        - Output encrypted block stream text, 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a9ab35ac8a3b4dcb67c6daded1181d1c2:
.. _cid-xf::security::details::aesctrdecrypt-2:

aesCtrDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesCtrDecrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& IV_strm,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e
	    )

aesCtrDecrypt is CTR decryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - IV_strm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintext

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a3831c1bb191a72d327fbb1d77f72abc6:
.. _cid-xf::security::details::aesecbencrypt:

aesEcbEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesEcbEncrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e
	    )

aesEcbEncrypt is ECB encryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - ciphertext

        - Output encrypted block stream text, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1ae56d1f897ebf63e46eef3c145b5b2fb3:
.. _cid-xf::security::details::aesecbdecrypt:

aesEcbDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesEcbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e
	    )

aesEcbDecrypt is ECB decryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - plaintext

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a250e87ace03ba32b464f52293c94f630:
.. _cid-xf::security::details::aesgcmencrypt:

aesGcmEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesGcmEncrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <96>>& IV_strm,
	    hls::stream <ap_uint <128>>& AAD_strm,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <128>>& tag_strm
	    )

aesGcmEncrypt is GCM encryption mode with AES single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - IV_strm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - AAD_strm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - ciphertext

        - Output encrypted block stream text, 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - tag_strm

        - The data tag

.. _doxid-namespacexf_1_1security_1_1details_1af2ababf0307ade760283de330b6b1694:
.. _cid-xf::security::details::aesgcmdecrypt:

aesGcmDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesGcmDecrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <96>>& IV_strm,
	    hls::stream <ap_uint <128>>& AAD_strm,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <128>>& tag_strm
	    )

aesGcmEncrypt is GCM decryption mode with AES single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertext

        - Input block stream text to be decrypted, 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - IV_strm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - AAD_strm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - plaintext

        - Output decrypted block stream text, 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - tag_strm

        - The data tag

.. _doxid-namespacexf_1_1security_1_1details_1a809f09a8ab840cec4c1da2980ddb992c:
.. _cid-xf::security::details::generateeky0:

generateEKY0
------------


.. code-block:: cpp
	
	#include "xf_security/gmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void generateEKY0 (
	    hls::stream <ap_uint <256>>& keyStrm,
	    hls::stream <ap_uint <96>>& ivStrm,
	    hls::stream <ap_uint <128>>& aadStrm,
	    hls::stream <ap_uint <128>>& hStrm,
	    hls::stream <ap_uint <128>>& ekyStrm
	    )

generateEKY0 generates H and E_K_Y0 based on AES-256.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyStrm

        - input key used in encryption, 256 bits for AES-256.

    *
        - ivStrm

        - initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - aadStrm

        - output 128 bits zero.

    *
        - hStrm

        - generate H by encrypting 128-bit 0.

    *
        - ekyStrm

        - generate E_K_Y0 by encrypting 128-bit data including IV.

.. _doxid-namespacexf_1_1security_1_1details_1a97de6aea5f185b3bbc1110b8d44f5d66:
.. _cid-xf::security::details::preprocessing:

preProcessing
-------------


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void preProcessing (
	    hls::stream <ap_uint <32>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <64>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm
	    )

Generate 512-bit processing blocks by padding and appending (pipeline).

The algorithm reference is : "The MD4 Message-Digest Algorithm". The optimization goal of this function is to yield a 512-bit block per cycle.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - msg_strm

        - The message being hashed.

    *
        - len_strm

        - The message length in byte.

    *
        - end_len_strm

        - The flag to signal end of input message stream.

    *
        - blk_strm

        - The 512-bit hash block.

    *
        - nblk_strm

        - The number of hash block for this message.

    *
        - end_nblk_strm

        - End flag for number of hash block.

.. _doxid-namespacexf_1_1security_1_1details_1a4ed47aeb7bbce0e05cd022266968a401:
.. _cid-xf::security::details::f:

F
-


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static ap_uint <32> F (
	    ap_uint <32> x,
	    ap_uint <32> y,
	    ap_uint <32> z
	    )

Perform function F as defined in standard.

The algorithm reference is : "The MD4 Message-Digest Algorithm".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - x

        - The first 32-bit operand.

    *
        - y

        - The second 32-bit operand.

    *
        - z

        - The third 32-bit operand.

.. _doxid-namespacexf_1_1security_1_1details_1ab39f5ae51b9e383d3eea44b1b92ac7fd:
.. _cid-xf::security::details::g-2:

G
-


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static ap_uint <32> G (
	    ap_uint <32> x,
	    ap_uint <32> y,
	    ap_uint <32> z
	    )

Perform function G as defined in standard.

The algorithm reference is : "The MD4 Message-Digest Algorithm".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - x

        - The first 32-bit operand.

    *
        - y

        - The second 32-bit operand.

    *
        - z

        - The third 32-bit operand.

.. _doxid-namespacexf_1_1security_1_1details_1a2be905306e2c2b33c4e425a035788002:
.. _cid-xf::security::details::h:

H
-


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static ap_uint <32> H (
	    ap_uint <32> x,
	    ap_uint <32> y,
	    ap_uint <32> z
	    )

Perform function H as defined in standard.

The algorithm reference is : "The MD4 Message-Digest Algorithm".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - x

        - The first 32-bit operand.

    *
        - y

        - The second 32-bit operand.

    *
        - z

        - The third 32-bit operand.

.. _doxid-namespacexf_1_1security_1_1details_1a970de8c8ba246fb16eeeb7b476744395:
.. _cid-xf::security::details::rotl:

ROTL
----


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> ROTL (
	    unsigned int n,
	    ap_uint <w> x
	    )

The implementation of rotate left (circular left shift) operation.

The implementation of rotate left (circular left shift) operation. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.

The algorithm reference is : "The MD4 Message-Digest Algorithm".

The algorithm reference is : "The MD5 Message-Digest Algorithm".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 32.

    *
        - n

        - Number of bits for input x to be shifted.

    *
        - x

        - Word to be rotated.

    *
        - w

        - The bit width of input x, default value is 32.

    *
        - n

        - Number of bits for input x to be shifted.

    *
        - x

        - Word to be rotated.

    *
        - w

        - The bit width of input x, default value is 32.

    *
        - n

        - Number of bits for input x to be shifted.

    *
        - x

        - Word to be rotated.

.. _doxid-namespacexf_1_1security_1_1details_1a20a9f7d47224cf6b98632f198085c3b3:
.. _cid-xf::security::details::md4round1:

MD4Round1
---------


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD4Round1 (
	    ap_uint <32>& a,
	    ap_uint <32> b,
	    ap_uint <32> c,
	    ap_uint <32> d,
	    ap_uint <32> X,
	    unsigned int s
	    )

The implementation of the function defined in round 1.

The algorithm reference is : "The MD4 Message-Digest Algorithm". The operation is defined as : a = (a + F(b, c, d) + X[k]) <<< s.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - The first 32-bit operand.

    *
        - b

        - The second 32-bit operand.

    *
        - c

        - The third 32-bit operand.

    *
        - d

        - The fourth 32-bit operand.

    *
        - X

        - The specific message word.

    *
        - s

        - Number of bits to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1ae85105f732c50c28a5b798ca05218488:
.. _cid-xf::security::details::md4round2:

MD4Round2
---------


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD4Round2 (
	    ap_uint <32>& a,
	    ap_uint <32> b,
	    ap_uint <32> c,
	    ap_uint <32> d,
	    ap_uint <32> X,
	    unsigned int s
	    )

The implementation of the function defined in round 2.

The algorithm reference is : "The MD4 Message-Digest Algorithm". The operation is defined as : a = (a + G(b, c, d) + X[k] + 0x5a827999) <<< s



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - The first 32-bit operand.

    *
        - b

        - The second 32-bit operand.

    *
        - c

        - The third 32-bit operand.

    *
        - d

        - The fourth 32-bit operand.

    *
        - X

        - The specific message word.

    *
        - s

        - Number of bits to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1a028eb29a040ea578d325df2419cb1f86:
.. _cid-xf::security::details::md4round3:

MD4Round3
---------


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD4Round3 (
	    ap_uint <32>& a,
	    ap_uint <32> b,
	    ap_uint <32> c,
	    ap_uint <32> d,
	    ap_uint <32> X,
	    unsigned int s
	    )

The implementation of the function defined in round 3.

The algorithm reference is : "The MD4 Message-Digest Algorithm". The operation is defined as : a = (a + H(b, c, d) + X[k] + 0x6ed9eba1) <<< s



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - The first 32-bit operand.

    *
        - b

        - The second 32-bit operand.

    *
        - c

        - The third 32-bit operand.

    *
        - d

        - The fourth 32-bit operand.

    *
        - X

        - The specific message word.

    *
        - s

        - Number of bits to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1a2adb2bc1599c7782927652ce2cb15001:
.. _cid-xf::security::details::md4digest:

MD4Digest
---------


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD4Digest (
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <64>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <128>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

The implementation of the digest part of MD4.

The algorithm reference is : "The MD4 Message-Digest Algorithm". The optimization goal of this function is for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - blk_strm

        - The 512-bit hash block.

    *
        - nblk_strm

        - The number of hash block for this message.

    *
        - end_nblk_strm

        - End flag for number of hash block.

    *
        - digest_strm

        - The digest (fingerprint) stream.

    *
        - end_digest_strm

        - Flag to signal the end of the result.

.. _doxid-namespacexf_1_1security_1_1details_1acc666b2bf029f8600ca8338b9ade5308:
.. _cid-xf::security::details::i:

I
-


.. code-block:: cpp
	
	#include "xf_security/md5.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static ap_uint <32> I (
	    ap_uint <32> x,
	    ap_uint <32> y,
	    ap_uint <32> z
	    )

Perform function I as defined in standard.

The algorithm reference is : "The MD5 Message-Digest Algorithm".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - x

        - The first 32-bit operand.

    *
        - y

        - The second 32-bit operand.

    *
        - z

        - The third 32-bit operand.

.. _doxid-namespacexf_1_1security_1_1details_1a8aad0f87e53721246d15f69c62c5c952:
.. _cid-xf::security::details::md5round1:

MD5Round1
---------


.. code-block:: cpp
	
	#include "xf_security/md5.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD5Round1 (
	    ap_uint <32>& a,
	    ap_uint <32> b,
	    ap_uint <32> c,
	    ap_uint <32> d,
	    ap_uint <32> X,
	    ap_uint <32> T,
	    unsigned int s
	    )

The implementation of the function defined in round 1.

The algorithm reference is : "The MD5 Message-Digest Algorithm". The operation is defined as : a = b + ((a + F(b, c, d) + X + T) <<< s).



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - The first 32-bit operand.

    *
        - b

        - The second 32-bit operand.

    *
        - c

        - The third 32-bit operand.

    *
        - d

        - The fourth 32-bit operand.

    *
        - X

        - The specific message word.

    *
        - T

        - the specific sine value.

    *
        - s

        - Number of bits to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1a5f8264d87fbbec143271cc46e8b1e373:
.. _cid-xf::security::details::md5round2:

MD5Round2
---------


.. code-block:: cpp
	
	#include "xf_security/md5.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD5Round2 (
	    ap_uint <32>& a,
	    ap_uint <32> b,
	    ap_uint <32> c,
	    ap_uint <32> d,
	    ap_uint <32> X,
	    ap_uint <32> T,
	    unsigned int s
	    )

The implementation of the function defined in round 2.

The algorithm reference is : "The MD5 Message-Digest Algorithm". The operation is defined as : a = b + ((a + G(b, c, d) + X + T) <<< s).



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - The first 32-bit operand.

    *
        - b

        - The second 32-bit operand.

    *
        - c

        - The third 32-bit operand.

    *
        - d

        - The fourth 32-bit operand.

    *
        - X

        - The specific message word.

    *
        - T

        - the specific sine value.

    *
        - s

        - Number of bits to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1aeb5496b145940ec18c416f43f7624c34:
.. _cid-xf::security::details::md5round3:

MD5Round3
---------


.. code-block:: cpp
	
	#include "xf_security/md5.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD5Round3 (
	    ap_uint <32>& a,
	    ap_uint <32> b,
	    ap_uint <32> c,
	    ap_uint <32> d,
	    ap_uint <32> X,
	    ap_uint <32> T,
	    unsigned int s
	    )

The implementation of the function defined in round 3.

The algorithm reference is : "The MD5 Message-Digest Algorithm". The operation is defined as : a = b + ((a + H(b, c, d) + X + T) <<< s).



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - The first 32-bit operand.

    *
        - b

        - The second 32-bit operand.

    *
        - c

        - The third 32-bit operand.

    *
        - d

        - The fourth 32-bit operand.

    *
        - X

        - The specific message word.

    *
        - T

        - the specific sine value.

    *
        - s

        - Number of bits to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1a0a95ee6bf223865609af232afba27405:
.. _cid-xf::security::details::md5round4:

MD5Round4
---------


.. code-block:: cpp
	
	#include "xf_security/md5.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD5Round4 (
	    ap_uint <32>& a,
	    ap_uint <32> b,
	    ap_uint <32> c,
	    ap_uint <32> d,
	    ap_uint <32> X,
	    ap_uint <32> T,
	    unsigned int s
	    )

The implementation of the function defined in round 4.

The algorithm reference is : "The MD5 Message-Digest Algorithm". The operation is defined as : a = b + ((a + I(b, c, d) + X + T) <<< s).



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - The first 32-bit operand.

    *
        - b

        - The second 32-bit operand.

    *
        - c

        - The third 32-bit operand.

    *
        - d

        - The fourth 32-bit operand.

    *
        - X

        - The specific message word.

    *
        - T

        - the specific sine value.

    *
        - s

        - Number of bits to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1a2ddf4cf6dc14376257ff7e17442672b6:
.. _cid-xf::security::details::md5digest:

MD5Digest
---------


.. code-block:: cpp
	
	#include "xf_security/md5.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void MD5Digest (
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <64>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <128>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

The implementation of the digest part of MD5.

The algorithm reference is : "The MD5 Message-Digest Algorithm". The optimization goal of this function is for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - blk_strm

        - The 512-bit hash block.

    *
        - nblk_strm

        - The number of hash block for this message.

    *
        - end_nblk_strm

        - End flag for number of hash block.

    *
        - digest_strm

        - The digest (fingerprint) stream.

    *
        - end_digest_strm

        - Flag to signal the end of the result.

.. _doxid-namespacexf_1_1security_1_1details_1aca8cb55fbef31d35daa39bd6bdedc185:
.. _cid-xf::security::details::aesofbencrypt:

aesOfbEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesOfbEncrypt (
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& initialization_vector,
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e
	    )

aesOfbEncrypt is OFB encryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in encryption, x bits for AES-x.

    *
        - initialization_vector

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertext

        - Output encrypted block stream text, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1ab8374ff37b115e73346542172406a128:
.. _cid-xf::security::details::aesofbdecrypt:

aesOfbDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesOfbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertext,
	    hls::stream <bool>& ciphertext_e,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey,
	    hls::stream <ap_uint <128>>& IV_strm,
	    hls::stream <ap_uint <128>>& plaintext,
	    hls::stream <bool>& plaintext_e
	    )

aesOfbDecrypt is OFB decryption mode with AES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - ciphertext_e

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkey

        - Input cipher key used in decryption, x bits for AES-x.

    *
        - IV_strm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintext

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1aa287aa18e11ee5285976ae925caaf740:
.. _cid-xf::security::details::multoperator:

multOperator
------------


.. code-block:: cpp
	
	#include "xf_security/poly1305.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	ap_uint <264> multOperator (
	    ap_uint <136> A,
	    ap_uint <128> B
	    )

The implementation of large bit-width multiplication, the result is A * B. The optimization goal of this function to improve timing.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - A

        - The input multiplicand.

    *
        - B

        - The input multiplier.



.. rubric:: Returns:

The output product.

.. _doxid-namespacexf_1_1security_1_1details_1a71994c0f57c81f9c8ae279199f4dc19d:
.. _cid-xf::security::details::poly1305imp:

poly1305Imp
-----------


.. code-block:: cpp
	
	#include "xf_security/poly1305.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void poly1305Imp (
	    hls::stream <ap_uint <256>>& keyStrm,
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <bool>& endLenStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

The implementation of poly1305.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyStrm

        - initail key

    *
        - payloadStrm

        - For a massage, input block stream text, 128 bits per block, less than 128 bits, high padding 0

    *
        - lenPldStrm

        - Length of payload in byte.

    *
        - endLenStrm

        - Flag to signal the end of the length streams.

    *
        - tagStrm

        - Return a 16-byte tag to to authenticate the message.

.. _doxid-namespacexf_1_1security_1_1details_1aafb581797dc3f702a969e22071e011aa:
.. _cid-xf::security::details::rc4imp:

rc4Imp
------


.. code-block:: cpp
	
	#include "xf_security/rc4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void rc4Imp (
	    hls::stream <ap_uint <8>>& keyStrm,
	    hls::stream <bool>& eKeyStrm,
	    hls::stream <ap_uint <8>>& plainStream,
	    hls::stream <bool>& ePlainStream,
	    hls::stream <ap_uint <8>>& cipherStream,
	    hls::stream <bool>& eCipherStream
	    )

Rc_4 is the basic function for stream ciphering keyLength defined as the number of bytes in the key and can be in the range 1<= keylength <=256, typically between 5 and 16, corresponding to a key length of 40-128 bits.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - keyStrm

        - initail key

    *
        - eKeyStrm

        - end flag of keyStrm

    *
        - plaintStrm

        - input plain text to be encrypted

    *
        - ePlaintStrm

        - the end flag of plaintStrm

    *
        - cipherStrm

        - output encrypted text

    *
        - eCipherStrm

        - the end flag of cipherStrm

.. _doxid-namespacexf_1_1security_1_1details_1af680f3585034296cc68b7b5fdb54d5f7:
.. _cid-xf::security::details::ch:

Ch
--


.. code-block:: cpp
	
	#include "xf_security/sha1.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> Ch (
	    ap_uint <w> x,
	    ap_uint <w> y,
	    ap_uint <w> z
	    )

The implementation of Ch(x,y,z), the sequence of logical functions of SHA-1 where 0 <= t <= 19. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.

The implementation of Ch(x,y,z). The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, y, and z, default value is 32.

    *
        - x

        - The first w-bit input word.

    *
        - y

        - The second w-bit input word.

    *
        - z

        - The third w-bit input word.

    *
        - w

        - The bit width of input x, y, and z, default value is 64.

    *
        - x

        - The first w-bit input word.

    *
        - y

        - The second w-bit input word.

    *
        - z

        - The third w-bit input word.

.. _doxid-namespacexf_1_1security_1_1details_1ae8fcb30e1e894f23cbad08704d5641eb:
.. _cid-xf::security::details::parity:

Parity
------


.. code-block:: cpp
	
	#include "xf_security/sha1.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> Parity (
	    ap_uint <w> x,
	    ap_uint <w> y,
	    ap_uint <w> z
	    )

The implementation of Parity(x,y,z), the sequence of logical functions of SHA-1 where 20 <= t <= 39, and 60 <= t <= 79. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, y, and z, default value is 32.

    *
        - x

        - The first w-bit input word.

    *
        - y

        - The second w-bit input word.

    *
        - z

        - The third w-bit input word.

.. _doxid-namespacexf_1_1security_1_1details_1a969e741d6d91783e2aa91c7b48d0bb52:
.. _cid-xf::security::details::maj:

Maj
---


.. code-block:: cpp
	
	#include "xf_security/sha1.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> Maj (
	    ap_uint <w> x,
	    ap_uint <w> y,
	    ap_uint <w> z
	    )

The implementation of Maj(x,y,z), the sequence of logical functions of SHA-1 where 40 <= t <= 59. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.

The implementation of Maj(x,y,z). The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, y, and z, default value is 32.

    *
        - x

        - The first w-bit input word.

    *
        - y

        - The second w-bit input word.

    *
        - z

        - The third w-bit input word.

    *
        - w

        - The bit width of input x, y, and z, default value is 64.

    *
        - x

        - The first w-bit input word.

    *
        - y

        - The second w-bit input word.

    *
        - z

        - The third w-bit input word.

.. _doxid-namespacexf_1_1security_1_1details_1a0d462e4e7b61a5e2be4340f425921756:
.. _cid-xf::security::details::dup_strm-3:

dup_strm
--------


.. code-block:: cpp
	
	#include "xf_security/sha1.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void dup_strm (
	    hls::stream <ap_uint <w>>& in_strm,
	    hls::stream <bool>& in_e_strm,
	    hls::stream <ap_uint <w>>& out1_strm,
	    hls::stream <bool>& out1_e_strm,
	    hls::stream <ap_uint <w>>& out2_strm,
	    hls::stream <bool>& out2_e_strm
	    )

Duplicate 1 input stream to 2 output streams.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of the streams.

    *
        - in_strm

        - Input stream to be duplicated.

    *
        - in_e_strm

        - End flag of input stream.

    *
        - out1_strm

        - The first output stream.

    *
        - out1_e_strm

        - End flag of the first output stream.

    *
        - out2_strm

        - The second output stream.

    *
        - out2_e_strm

        - End flag of the second output stream.

.. _doxid-namespacexf_1_1security_1_1details_1a2e984dfcaee9d54662ccb5529d80a43e:
.. _cid-xf::security::details::generatemsgschedule-2:

generateMsgSchedule
-------------------


.. code-block:: cpp
	
	#include "xf_security/sha1.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void generateMsgSchedule (
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <64>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <w>>& w_strm
	    )

Generate message schedule W (80 words) in stream. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of message schedule W which defined in the standard.

    *
        - blk_strm

        - Message block stream.

    *
        - nblk_strm

        - Number of message block stream.

    *
        - end_nblk_strm

        - End flag for number of message block stream.

    *
        - w_strm

        - The message schedule in stream.

.. _doxid-namespacexf_1_1security_1_1details_1a76f31de65da1c8aaa1fdf113381ab3c9:
.. _cid-xf::security::details::sha1digest:

SHA1Digest
----------


.. code-block:: cpp
	
	#include "xf_security/sha1.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void SHA1Digest (
	    hls::stream <ap_uint <w>>& w_strm,
	    hls::stream <ap_uint <64>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <5*w>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

This function performs the computation of the secure hash algorithm.

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of each input message word, default value is 32.

    *
        - w_strm

        - Message schedule stream.

    *
        - nblk_strm

        - Number of message block stream.

    *
        - end_nblk_strm

        - End flag for number of message block stream.

    *
        - digest_strm

        - Output digest stream.

    *
        - end_digest_strm

        - End flag for output digest stream.

.. _doxid-namespacexf_1_1security_1_1details_1ac15fc0fcf45caa45011a950816cf21d6:
.. _cid-xf::security::details::preprocessing-2:

preProcessing
-------------


preProcessing overload (1)
++++++++++++++++++++++++++


.. code-block:: cpp
	
	#include "xf_security/sha224_256.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void preProcessing (
	    hls::stream <ap_uint <32>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <:ref:`SHA256Block<doxid-structxf_1_1security_1_1details_1_1_s_h_a256_block>`>& blk_strm,
	    hls::stream <uint64_t>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm
	    )

Generate 512bit processing blocks for SHA224/SHA256 (pipeline) with const width. The performance goal of this function is to yield a 512b block per cycle.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - msg_strm

        - the message being hashed.

    *
        - len_strm

        - the message length in byte.

    *
        - end_len_strm

        - that flag to signal end of input.

    *
        - blk_strm

        - the 512-bit hash block.

    *
        - nblk_strm

        - the number of hash block for this message.

    *
        - end_nblk_strm

        - end flag for number of hash block.

.. _doxid-namespacexf_1_1security_1_1details_1a50ff8f39a454ffcb6ff9b5f6c3f99e57:
.. _cid-xf::security::details::preprocessing-3:

preProcessing overload (2)
++++++++++++++++++++++++++


.. code-block:: cpp
	
	#include "xf_security/sha224_256.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void preProcessing (
	    hls::stream <ap_uint <64>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <:ref:`SHA256Block<doxid-structxf_1_1security_1_1details_1_1_s_h_a256_block>`>& blk_strm,
	    hls::stream <uint64_t>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm
	    )

Generate 512bit processing blocks for SHA224/SHA256 (pipeline) with const width. The performance goal of this function is to yield a 512b block per cycle.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - msg_strm

        - the message being hashed.

    *
        - len_strm

        - the message length in byte.

    *
        - end_len_strm

        - that flag to signal end of input.

    *
        - blk_strm

        - the 512-bit hash block.

    *
        - nblk_strm

        - the number of hash block for this message.

    *
        - end_nblk_strm

        - end flag for number of hash block.

.. _doxid-namespacexf_1_1security_1_1details_1a5d16559a5979466cbd93e7cdcc4a8da7:
.. _cid-xf::security::details::sha256digest:

sha256Digest
------------


.. code-block:: cpp
	
	#include "xf_security/sha224_256.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <int h_width>
	void sha256Digest (
	    hls::stream <uint64_t>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <uint32_t>& w_strm,
	    hls::stream <ap_uint <h_width>>& hash_strm,
	    hls::stream <bool>& end_hash_strm
	    )

Digest message blocks and emit final hash.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - h_width

        - the hash width(type).

    *
        - nblk_strm

        - number of message block.

    *
        - end_nblk_strm

        - end flag for number of message block.

    *
        - hash_strm

        - the hash result stream.

    *
        - end_hash_strm

        - end flag for hash result.

.. _doxid-namespacexf_1_1security_1_1details_1a0b6eb399d9f28f5cd04d96c79c6de842:
.. _cid-xf::security::details::sha256_top:

sha256_top
----------


.. code-block:: cpp
	
	#include "xf_security/sha224_256.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int m_width,
	    int h_width
	    >
	void sha256_top (
	    hls::stream <ap_uint <m_width>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <h_width>>& hash_strm,
	    hls::stream <bool>& end_hash_strm
	    )

SHA-256/224 implementation top overload for ap_uint input.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - m_width

        - the input message stream width.

    *
        - h_width

        - the output hash stream width.

    *
        - msg_strm

        - the message being hashed.

    *
        - len_strm

        - the length message being hashed in byte.

    *
        - end_len_strm

        - end flag stream of input, one per message.

    *
        - hash_strm

        - the result.

    *
        - end_hash_strm

        - end falg stream of output, one per hash.

.. _doxid-namespacexf_1_1security_1_1details_1a7273b76146abec19a5883c69c2ba00d3:
.. _cid-xf::security::details::rotl-2:

ROTL
----


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w = 64>
	ap_uint <w> ROTL (
	    ap_uint <w> x,
	    unsigned int n
	    )

The implementation of rotate left (circular left shift) operation. The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - n

        - Number of bits for input x to be shifted.

    *
        - x

        - Word to be rotated.

.. _doxid-namespacexf_1_1security_1_1details_1a19880785102ffc1fc684abca7cdd1f79:
.. _cid-xf::security::details::keccak_f:

KECCAK_f
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void KECCAK_f (ap_uint <64> stateArray [25])

The implementation of KECCAK-f permutation function.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions". The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - stateArray

        - The 5*5*64 state array defined in standard.

.. _doxid-namespacexf_1_1security_1_1details_1abfb4bb749ca38ce965b453a3146c23a4:
.. _cid-xf::security::details::sha3digest:

sha3Digest
----------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int hashLen = 32>
	void sha3Digest (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <8*hashLen>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

This function performs the computation of SHA-3.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions". The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - hashLen

        - The width of the digest in byte, default value is 32 (SHA3-256).

    *
        - msgStrm

        - The message being hashed.

    *
        - msgLenStrm

        - Message length in byte.

    *
        - endMsgLenStrm

        - The flag to signal end of input message stream.

    *
        - digestStrm

        - Output digest stream.

    *
        - endDigestStrm

        - End flag for output digest stream.

.. _doxid-namespacexf_1_1security_1_1details_1ad91823d93ae8c1b060f9e6c9e0ef21d8:
.. _cid-xf::security::details::shakexof:

shakeXOF
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int hashLen = 16>
	void shakeXOF (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <8*hashLen>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

This function performs the computation of SHAKE.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions". The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - hashLen

        - The width of the digest in byte, default value is 16 (SHAKE-128).

    *
        - msgStrm

        - The message being hashed.

    *
        - msgLenStrm

        - Message length in byte.

    *
        - endMsgLenStrm

        - The flag to signal end of input message stream.

    *
        - digestStrm

        - Output digest stream.

    *
        - endDigestStrm

        - End flag for output digest stream.

.. _doxid-namespacexf_1_1security_1_1details_1af17bff1339abe5a302bd1adbcec2789e:
.. _cid-xf::security::details::preprocessing-4:

preProcessing
-------------


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	static void preProcessing (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <128>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <128>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm
	    )

Generate 1024-bit processing blocks by padding and appending (pipeline).

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The optimization goal of this function is to yield a 1024-bit block per cycle.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of each input message word, default value is 64.

    *
        - msg_strm

        - The message being hashed.

    *
        - len_strm

        - The message length in byte.

    *
        - end_len_strm

        - The flag to signal end of input message stream.

    *
        - blk_strm

        - The 1024-bit hash block.

    *
        - nblk_strm

        - The number of hash block for this message.

    *
        - end_nblk_strm

        - End flag for number of hash block.

.. _doxid-namespacexf_1_1security_1_1details_1aefd2a0c9c01be79d85e2f6fad38db4c7:
.. _cid-xf::security::details::shr:

SHR
---


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> SHR (
	    unsigned int n,
	    ap_uint <w> x
	    )

The implementation of right shift operation. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - n

        - Number of bits for input x to be shifted.

    *
        - x

        - Word to be shifted.

.. _doxid-namespacexf_1_1security_1_1details_1a1ab9416cc0d63e84a70e4030f328a9ff:
.. _cid-xf::security::details::rotr-2:

ROTR
----


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> ROTR (
	    unsigned int n,
	    ap_uint <w> x
	    )

The implementation of rotate right (circular right shift) operation. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - n

        - Number of bits for input x to be shifted.

    *
        - x

        - Word to be rotated.

.. _doxid-namespacexf_1_1security_1_1details_1ab28659aeaee00ecba95297be65f7ccc9:
.. _cid-xf::security::details::bsig0:

BSIG0
-----


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> BSIG0 (ap_uint <w> x)

The implementation of upper-case letter sigma 0. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - x

        - The operand.

.. _doxid-namespacexf_1_1security_1_1details_1af75e535f0f90def371f9154e885cd10c:
.. _cid-xf::security::details::bsig1:

BSIG1
-----


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> BSIG1 (ap_uint <w> x)

The implementation of upper-case letter sigma 1. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - x

        - The operand.

.. _doxid-namespacexf_1_1security_1_1details_1a5ba691c73c7faa20521a395fc30e8fc1:
.. _cid-xf::security::details::ssig0:

SSIG0
-----


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> SSIG0 (ap_uint <w> x)

The implementation of lower-case letter sigma 0. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - x

        - The operand.

.. _doxid-namespacexf_1_1security_1_1details_1a8b8749a6355403e195b80e3ce8152ccf:
.. _cid-xf::security::details::ssig1:

SSIG1
-----


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	ap_uint <w> SSIG1 (ap_uint <w> x)

The implementation of lower-case letter sigma 1. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of input x, default value is 64.

    *
        - x

        - The operand.

.. _doxid-namespacexf_1_1security_1_1details_1aa5fc18d5c7c89a0fe0f9be40bd602dcc:
.. _cid-xf::security::details::generatemsgschedule-3:

generateMsgSchedule
-------------------


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void generateMsgSchedule (
	    hls::stream <:ref:`blockType<doxid-structxf_1_1security_1_1details_1_1block_type>`>& blk_strm,
	    hls::stream <ap_uint <128>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <w>>& w_strm
	    )

Generate message schedule W (80 words) in stream. The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of message schedule W which defined in the standard, default value is 64.

    *
        - blk_strm

        - Message block stream.

    *
        - nblk_strm

        - Number of message block stream.

    *
        - end_nblk_strm

        - End flag for number of message block stream.

    *
        - w_strm

        - The message schedule in stream.

.. _doxid-namespacexf_1_1security_1_1details_1a4b04850498c5dc7230eb42c82446551e:
.. _cid-xf::security::details::sha512digest:

SHA512Digest
------------


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int w,
	    unsigned int hash_width
	    >
	void SHA512Digest (
	    hls::stream <ap_uint <w>>& w_strm,
	    hls::stream <ap_uint <128>>& nblk_strm,
	    hls::stream <bool>& end_nblk_strm,
	    hls::stream <ap_uint <hash_width>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

This function performs the computation of SHA-512.

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of each input message word, default value is 64.

    *
        - hash_width

        - The bit width of hash width, which depends on specific algorithm.

    *
        - w_strm

        - Message schedule stream.

    *
        - nblk_strm

        - Number of message block stream.

    *
        - end_nblk_strm

        - End flag for number of message block stream.

    *
        - digest_strm

        - Output digest stream.

    *
        - end_digest_strm

        - End flag for output digest stream.

.. _doxid-namespacexf_1_1security_1_1details_1ae25a12dc808b51fc3615ac718eb1c487:
.. _cid-xf::security::details::sha512top:

sha512Top
---------


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int w,
	    unsigned int hash_width
	    >
	void sha512Top (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <128>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <hash_width>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

Top of SHA-512.

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The implementation dataflows the pre-processing part and message digest part.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of each input message word, default value is 64.

    *
        - hash_width

        - The bit width of hash width, which depends on specific algorithm.

    *
        - msg_strm

        - The message being hashed.

    *
        - len_strm

        - The message length in byte.

    *
        - end_len_strm

        - The flag to signal end of input message stream.

    *
        - digest_strm

        - Output digest stream.

    *
        - end_digest_strm

        - End flag for output digest stream.

.. _doxid-namespacexf_1_1security_1_1details_1ada00480a7c97b1592a179debb327e2cb:
.. _cid-xf::security::details::aesxtsencrypt:

aesXtsEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/xts.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesXtsEncrypt (
	    hls::stream <ap_uint <128>>& plaintext_strm,
	    hls::stream <bool>& plaintext_e_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey_strm,
	    hls::stream <ap_uint <128>>& initialization_vector_strm,
	    hls::stream <ap_uint <128>>& ciphertext_strm,
	    hls::stream <bool>& ciphertext_e_strm
	    )

aesXtsEncrypt is XTS encryption mode with AES single block cipher.

The algorithm reference is : "IEEE Standard for Cryptographic Protection of
Data on Block-Oriented Storage Devices" The implementation is optimized for better performance in FPGA.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - plaintext_strm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - plaintext_e_strm

        - End flag of block stream plaintext, 1 bit.

    *
        - len_strm

        - Total length of plaintext in bit, 64 bits.

    *
        - cipherkey_strm

        - Input two cipher key used in encryption, x bits for AES-x.

    *
        - initialization_vector_strm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertext_strm

        - Output encrypted block stream text, 128 bits.

    *
        - ciphertext_e_strm

        - End flag of stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1_1details_1a945feb3736d61e840071433b6cb1829f:
.. _cid-xf::security::details::aesxtsdecrypt:

aesXtsDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/xts.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int _keyWidth = 256>
	void aesXtsDecrypt (
	    hls::stream <ap_uint <128>>& ciphertext_strm,
	    hls::stream <bool>& ciphertext_e_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <ap_uint <_keyWidth>>& cipherkey_strm,
	    hls::stream <ap_uint <128>>& initialization_vector_strm,
	    hls::stream <ap_uint <128>>& plaintext_strm,
	    hls::stream <bool>& plaintext_e_strm
	    )

aesXtsDecrypt is XTS decryption mode with AES single block cipher.

The algorithm reference is : "IEEE Standard for Cryptographic Protection of
Data on Block-Oriented Storage Devices" The implementation is optimized for better performance in FPGA.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - _keyWidth

        - The bit-width of the cipher key, which is 128, 192, or 256.

    *
        - ciphertext_strm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - ciphertext_e_strm

        - End flag of block stream ciphertext, 1 bit.

    *
        - len_strm

        - Total length of plaintext in bit, 64 bits.

    *
        - cipherkey_strm

        - Input two cipher key used in decryption, x bits for AES-x.

    *
        - initialization_vector_strm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - plaintext_strm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - plaintext_e_strm

        - End flag of block stream plaintext, 1 bit.

