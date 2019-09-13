.. index:: pair: namespace; security
.. _doxid-namespacexf_1_1security:
.. _cid-xf::security:

namespace security
==================

.. toctree::
	:hidden:

	namespace_xf_security_detail.rst
	namespace_xf_security_details.rst
	namespace_xf_security_internal.rst
	class_xf_security_aesDec.rst
	class_xf_security_aesDec-2.rst
	class_xf_security_aesEnc.rst
	class_xf_security_aesEnc-2.rst



.. _doxid-namespacexf_1_1security_1a1d60d0862b320446d55551927015864d:
.. _cid-xf::security::sbox_rcon:
.. _doxid-namespacexf_1_1security_1a3eb01e133888e7a3ca358c23cd431cab:
.. _cid-xf::security::sbox_mix_col_1:
.. _doxid-namespacexf_1_1security_1a6a20d9aab86218fdbca0e5025c70f0e7:
.. _cid-xf::security::isbox:
.. _doxid-namespacexf_1_1security_1a236569f97ff7cd7a2c3bc3d2569b7a00:
.. _cid-xf::security::sbox:
.. _doxid-namespacexf_1_1security_1a2dcf4295949aa23af393274da8e7cc3f:
.. _cid-xf::security::gtbox:
.. _doxid-namespacexf_1_1security_1a128b80f49b3054a5c73fa60c3f33ee2d:
.. _cid-xf::security::sboxenc:
.. _doxid-namespacexf_1_1security_1ab103b183b5674a0510353c1f69462a60:
.. _cid-xf::security::rcon:
.. _doxid-namespacexf_1_1security_1af6ef1ec1ce711d7d5acf212b4088a300:
.. _cid-xf::security::printvar:
.. _doxid-namespacexf_1_1security_1a7809338a8b042a25e899513366731b70:
.. _cid-xf::security::printvar-2:
.. _doxid-namespacexf_1_1security_1a17416cdae7bafa80a9f8eaa8d1d196ea:
.. _cid-xf::security::processwordtemp:
.. _doxid-namespacexf_1_1security_1aa0a31b64c60951dafc4f026c8f70fbdd:
.. _cid-xf::security::aes128encrypt:
.. _doxid-namespacexf_1_1security_1a8b7f6fbaf050cb27141541a4b7bb234e:
.. _cid-xf::security::aes192encrypt:
.. ref-code-block:: cpp
	:class: overview-code-block

	// namespaces

	namespace :ref:`xf::security::detail<doxid-namespacexf_1_1security_1_1detail>`
	namespace :ref:`xf::security::details<doxid-namespacexf_1_1security_1_1details>`
	namespace :ref:`xf::security::internal<doxid-namespacexf_1_1security_1_1internal>`

	// classes

	template <>
	class :ref:`aesDec <256><doxid-classxf_1_1security_1_1aes_dec_3_01256_01_4>` 

	template <int W>
	class :ref:`aesDec<doxid-classxf_1_1security_1_1aes_dec>` 

	template <>
	class :ref:`aesEnc <256><doxid-classxf_1_1security_1_1aes_enc_3_01256_01_4>` 

	template <int W>
	class :ref:`aesEnc<doxid-classxf_1_1security_1_1aes_enc>` 

	// global variables

	const ap_uint <8> sbox_Rcon[2048]
	const ap_uint <16> sbox_mix_col_1[256]
	const ap_uint <8> isbox[256]
	const ap_uint <8> sbox[2048]
	const ap_uint <32> gtbox[256]
	const ap_uint <8> sboxEnc[256]
	const ap_uint <8> Rcon[10]


.. FunctionSection




.. _doxid-namespacexf_1_1security_1a48b43c1a4198d7367833720d9b1378a3:
.. _cid-xf::security::aes256encrypt:

aes256Encrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/aes.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Encrypt (
	    ap_uint <128> plaintext,
	    ap_uint <256> cipherkey,
	    ap_uint <128>& ciphertext
	    )

aes256Encrypt is the basic function for ciphering one block with one cipher key



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintext

        - input one word plain text to be encrypted, 128 bits.

    *
        - cipherkey

        - input cipher key, 256 bits.

    *
        - ciphertext

        - output one word encrypted text, 128 bit.

.. _doxid-namespacexf_1_1security_1a8b392ab72e2f3853eeff05348c5fa076:
.. _cid-xf::security::aes256decrypt:

aes256Decrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/aes.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Decrypt (
	    ap_uint <128> ciphertext,
	    ap_uint <256> cipherkey,
	    ap_uint <128>& plaintext
	    )

aes256Decrypt is the basic function for decrypting one block with one cipher key



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertext

        - input one word cipher text to be decrypted, 128 bits.

    *
        - plainkey

        - input plain key, 256 bits.

    *
        - plaintext

        - output one word encrypted text, 128 bit.

.. _doxid-namespacexf_1_1security_1a874379e9d8a0c1e63097ba0d742c4e1d:
.. _cid-xf::security::aes128decrypt:

aes128Decrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/aes.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128Decrypt (
	    ap_uint <128> ciphertext,
	    ap_uint <128> cipherkey,
	    ap_uint <128>& plaintext
	    )

aes128Decrypt is the basic function for decrypting one block with one cipher key



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertext

        - input one word cipher text to be decrypted, 128 bits.

    *
        - plainkey

        - input plain key, 128 bits.

    *
        - plaintext

        - output one word encrypted text, 128 bit.

.. _doxid-namespacexf_1_1security_1afe60f26308f46392c708e07096062568:
.. _cid-xf::security::aes192decrypt:

aes192Decrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/aes.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192Decrypt (
	    ap_uint <128> ciphertext,
	    ap_uint <192> cipherkey,
	    ap_uint <128>& plaintext
	    )

aes192Decrypt is the basic function for decrypting one block with one 192-bit cipher key



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertext

        - input one word cipher text to be decrypted, 128 bits.

    *
        - plainkey

        - input plain key, 192 bits.

    *
        - plaintext

        - output one word encrypted text, 128 bit.

.. _doxid-namespacexf_1_1security_1aa3333f8d1713b88c61936977f846681d:
.. _cid-xf::security::rsa:

rsa
---


.. code-block:: cpp
	
	#include "xf_security/asymmetric.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    int KeyLength,
	    int BlockWidth
	    >
	void rsa (
	    ap_uint <KeyLength> message,
	    ap_uint <KeyLength> N,
	    ap_uint <KeyLength> key,
	    ap_uint <KeyLength>& result
	    )

RSA encryption/decryption function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - KeyLength

        - Length of key, usually 1024/2048

    *
        - BlockWidth

        - Basic multiplication width, should be picked according to cards. Also KeyLength shoud be divisible by BlockWidth.

    *
        - message

        - Message to be encrypted or ciphertxt to be decrypted.

    *
        - N

        - Served as modulus in modular operation.

    *
        - key

        - Encryption/decryption key used.

    *
        - result

        - encrypiton/decryption result.

.. _doxid-namespacexf_1_1security_1abe39c66e4cc328feeea53d44be6259ef:
.. _cid-xf::security::blake2b:

blake2b
-------


.. code-block:: cpp
	
	#include "xf_security/blake2b.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void blake2b (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <128>>& msg_len_strm,
	    hls::stream <ap_uint <w>>& key_strm,
	    hls::stream <ap_uint <8>>& key_len_strm,
	    hls::stream <ap_uint <8>>& out_len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <8*w>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

Top of BLAKE2B.

The algorithm reference is : "The BLAKE2 Cryptographic Hash and Message Authentication Code (MAC)". The implementation dataflows the sub-modules.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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
        - out_len_strm

        - Result hash value length in byte (0 < out_len < 64).

    *
        - end_len_strm

        - The flag to signal end of input message stream.

    *
        - digest_strm

        - The digest (hash value) stream.

    *
        - end_digest_strm

        - Flag to signal the end of the result.

.. _doxid-namespacexf_1_1security_1a46333afdffd3d1c2395ff65d2ea22437:
.. _cid-xf::security::descbcencrypt:

desCbcEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCbcEncrypt (
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

desCbcEncrypt is CBC encryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES encrypition, 64 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1aca909bfbf44c09656ca2d6b0b4d7e240:
.. _cid-xf::security::descbcdecrypt:

desCbcDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCbcDecrypt (
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

desCbcDecrypt is CBC decryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES decrypition, 64 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1ab5f7d57eb969a21a65144956528466d9:
.. _cid-xf::security::aes128cbcencrypt:

aes128CbcEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128CbcEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128CbcEncrypt is CBC encryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1aff65b65cf960ffdac34ea8eb8e3f2e6d:
.. _cid-xf::security::aes128cbcdecrypt:

aes128CbcDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128CbcDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128CbcDecrypt is CBC decryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1aaa579217a7a3ab9f952316ac5d97e666:
.. _cid-xf::security::aes192cbcencrypt:

aes192CbcEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192CbcEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes192CbcEncrypt is CBC encryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a7c621e1c63ab1921542150b90a44d063:
.. _cid-xf::security::aes192cbcdecrypt:

aes192CbcDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192CbcDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes192CbcDecrypt is CBC decryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a777e324e59ad3460a43c4e66fd5e3741:
.. _cid-xf::security::aes256cbcencrypt:

aes256CbcEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256CbcEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256CbcEncrypt is CBC encryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a3957e3e39c619a7c19889f8010ed4651:
.. _cid-xf::security::aes256cbcdecrypt:

aes256CbcDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cbc.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256CbcDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256CbcDecrypt is CBC decryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1ad46f1f886572d932d63aa7cb814ba1c2:
.. _cid-xf::security::aes128ccmencrypt:

aes128CcmEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8
	    >
	void aes128CcmEncrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
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

aes128CcmEncrypt is CCM encryption mode with AES-128 single block cipher.

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

.. _doxid-namespacexf_1_1security_1a20a4d5e439c3e3c931adc74039cddf70:
.. _cid-xf::security::aes128ccmdecrypt:

aes128CcmDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8
	    >
	void aes128CcmDecrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
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

aes128CcmDecrypt is CCM decryption mode with AES-128 single block cipher.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a6eb5aba07a922e2f99491fa56d072667:
.. _cid-xf::security::aes192ccmencrypt:

aes192CcmEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8
	    >
	void aes192CcmEncrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
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

aes192CcmEncrypt is CCM encryption mode with AES-192 single block cipher.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1aaa920c49e27e6963ccdb29fe39bb1492:
.. _cid-xf::security::aes192ccmdecrypt:

aes192CcmDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8
	    >
	void aes192CcmDecrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
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

aes192CcmDecrypt is CCM decryption mode with AES-192 single block cipher.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1ab6f66f04e25bb14520961acf9b89e0ad:
.. _cid-xf::security::aes256ccmencrypt:

aes256CcmEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8
	    >
	void aes256CcmEncrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
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

aes256CcmEncrypt is CCM encryption mode with AES-256 single block cipher.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a9e7730079a9b9503d1d9262ee02c2f03:
.. _cid-xf::security::aes256ccmdecrypt:

aes256CcmDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ccm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int _t = 16,
	    unsigned int _q = 8
	    >
	void aes256CcmDecrypt (
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
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

aes256CcmDecrypt is CCM decryption mode with AES-256 single block cipher.

The algorithm reference is: "Recommendation for Block Cipher Modes of Operation: The CCM Mode for Authentication and
Confidentiality" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a41714abe8a575750d2599c5c501a8766:
.. _cid-xf::security::descfb1encrypt:

desCfb1Encrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCfb1Encrypt (
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

desCfb1Encrypt is CFB1 encryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES encrypition, 64 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a3299e13c09434efbf2d482fa25ef1e7d:
.. _cid-xf::security::descfb1decrypt:

desCfb1Decrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCfb1Decrypt (
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

desCfb1Decrypt is CFB1 decryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES decrypition, 64 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a9602b6c267031d5d254d3dd758ddbc90:
.. _cid-xf::security::aes128cfb1encrypt:

aes128Cfb1Encrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128Cfb1Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128Cfb1Encrypt is CFB1 encryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a16c6b1407dbf578be20085c0a7e19723:
.. _cid-xf::security::aes128cfb1decrypt:

aes128Cfb1Decrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128Cfb1Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128Cfb1Decrypt is CFB1 decryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1aaf7c290c22ac580e7c96b9df7e2cced6:
.. _cid-xf::security::aes192cfb1encrypt:

aes192Cfb1Encrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192Cfb1Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes192Cfb1Encrypt is CFB1 encryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1ae6227cb7ba75a2c9a9cfee7898d952cd:
.. _cid-xf::security::aes192cfb1decrypt:

aes192Cfb1Decrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192Cfb1Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes192Cfb1Decrypt is CFB1 decryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a33ed8bcb9733b1b31f2a2bff67cfbd55:
.. _cid-xf::security::aes256cfb1encrypt:

aes256Cfb1Encrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Cfb1Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256Cfb1Encrypt is CFB1 encryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a6583d392c603d07a6c09dcf6e1abed0a:
.. _cid-xf::security::aes256cfb1decrypt:

aes256Cfb1Decrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Cfb1Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256Cfb1Decrypt is CFB1 decryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a3c23bf745edfebf653478d17162c01c7:
.. _cid-xf::security::descfb8encrypt:

desCfb8Encrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCfb8Encrypt (
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

desCfb8Encrypt is CFB8 encryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES encrypition, 64 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a54ebb64875b4074b8f376ceec583d538:
.. _cid-xf::security::descfb8decrypt:

desCfb8Decrypt
--------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCfb8Decrypt (
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

desCfb8Decrypt is CFB8 decryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES decrypition, 64 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a5d18b3b4e51e499b7dfc7add49cdd0b2:
.. _cid-xf::security::aes128cfb8encrypt:

aes128Cfb8Encrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128Cfb8Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128Cfb8Encrypt is CFB8 encryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a8ecc4ddbe99a6195bdf8dbe8f2643053:
.. _cid-xf::security::aes128cfb8decrypt:

aes128Cfb8Decrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128Cfb8Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128Cfb8Decrypt is CFB8 decryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1af1ef9abb2960c95dafdd9629faadcddb:
.. _cid-xf::security::aes192cfb8encrypt:

aes192Cfb8Encrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192Cfb8Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes192Cfb8Encrypt is CFB8 encryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1afe3217cb98ded0c8846f1ba2f3e58279:
.. _cid-xf::security::aes192cfb8decrypt:

aes192Cfb8Decrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192Cfb8Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes192Cfb8Decrypt is CFB8 decryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1ab4e75a7c333fc3bfe1acc708977522c7:
.. _cid-xf::security::aes256cfb8encrypt:

aes256Cfb8Encrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Cfb8Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256Cfb8Encrypt is CFB8 encryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a6352656455b55672a253449c507b017b:
.. _cid-xf::security::aes256cfb8decrypt:

aes256Cfb8Decrypt
-----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Cfb8Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256Cfb8Decrypt is CFB8 decryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a1748c1f2d56850c35b3b4dfa3f54b182:
.. _cid-xf::security::descfb128encrypt:

desCfb128Encrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCfb128Encrypt (
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

desCfb128Encrypt is CFB128 encryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES encrypition, 64 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1af9561ddb468c1de9094c0a9bba75bdc0:
.. _cid-xf::security::descfb128decrypt:

desCfb128Decrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desCfb128Decrypt (
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

desCfb128Decrypt is CFB128 decryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES decrypition, 64 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1ac3f3c68a5ad2550d6e879b0aeca8d519:
.. _cid-xf::security::aes128cfb128encrypt:

aes128Cfb128Encrypt
-------------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128Cfb128Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128Cfb128Encrypt is CFB128 encryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a0e92f7d7ad09577a3a5a316fa985ebfc:
.. _cid-xf::security::aes128cfb128decrypt:

aes128Cfb128Decrypt
-------------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128Cfb128Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128Cfb128Decrypt is CFB128 decryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a8b9de6ac135cc7c6949f96c03e6a2749:
.. _cid-xf::security::aes192cfb128encrypt:

aes192Cfb128Encrypt
-------------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192Cfb128Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes192Cfb128Encrypt is CFB128 encryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a293b209e35cf6e4aa61b53d39b190c90:
.. _cid-xf::security::aes192cfb128decrypt:

aes192Cfb128Decrypt
-------------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192Cfb128Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes192Cfb128Decrypt is CFB128 decryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a6286a22b0fa037776b7fa1d7e9214c7b:
.. _cid-xf::security::aes256cfb128encrypt:

aes256Cfb128Encrypt
-------------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Cfb128Encrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256Cfb128Encrypt is CFB128 encryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each text block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each cipher block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1aacbd3bd862cceb7bb3bd7af8b3a850df:
.. _cid-xf::security::aes256cfb128decrypt:

aes256Cfb128Decrypt
-------------------


.. code-block:: cpp
	
	#include "xf_security/cfb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Cfb128Decrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256Cfb128Decrypt is CFB128 decryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a69def70ab12428ea13c129eb577599c7:
.. _cid-xf::security::chacha20:

chacha20
--------


.. code-block:: cpp
	
	#include "xf_security/chacha20.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void chacha20 (
	    hls::stream <ap_uint <256>>& keyStrm,
	    hls::stream <ap_uint <128>>& counterNonceStrm,
	    hls::stream <ap_uint <8>>& plainStrm,
	    hls::stream <bool>& ePlainStrm,
	    hls::stream <ap_uint <8>>& cipherStrm,
	    hls::stream <bool>& eCipherStrm
	    )

chahcha20 is a basic function for stream ciphering when key is "keylayout-chacha", its layout in a 256-bit ap_uint<> likes this,

0 - 7 bit: 'k' 8 - 15 bit: 'e' 16 - 23 bit: 'y' 24 - 31 bit: 'l' ... 232- 239 bit: 'c' 240- 247 bit: 'h' 248- 255 bit: 'a'

state matrix: s[0] s[1] s[2] s[3] s[4] s[5] s[6] s[7] s[8] s[9] s[10] s[11] s[12] s[13] s[14] s[15]

128bits counterNonceStrm = counter 32 bits + nonce 96 bits the layout of the data from counteStrm 0-31 bit: counter s[12] 32-63 bit: nonce1 s[13] 64-95 bit: nonce2 s[14] 96-127 bit: nonce3 s[15]



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

.. _doxid-namespacexf_1_1security_1a664918bb4a2b04e1aa37c5c0a57b7c07:
.. _cid-xf::security::aes128ctrencrypt:

aes128CtrEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128CtrEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128CtrEncrypt is CTR encryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1aeaa3dc664aae554de709b6f64a830c14:
.. _cid-xf::security::aes128ctrdecrypt:

aes128CtrDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128CtrDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128CtrDecrypt is CTR decryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a5d635faad3bf9a1850fb005a4938c9cc:
.. _cid-xf::security::aes192ctrencrypt:

aes192CtrEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192CtrEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes192CtrEncrypt is CTR encryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a779d4970310275226aee441c471147b9:
.. _cid-xf::security::aes192ctrdecrypt:

aes192CtrDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192CtrDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes192CtrDecrypt is CTR decryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a4b99260252986a745bda2417076807f3:
.. _cid-xf::security::aes256ctrencrypt:

aes256CtrEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256CtrEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256CtrEncrypt is CTR encryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a72c8d60bd86d2076a2c89a604b9749b7:
.. _cid-xf::security::aes256ctrdecrypt:

aes256CtrDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ctr.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256CtrDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256CtrDecrypt is CTR decryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1ad974b89188fa179991041fc5a551df39:
.. _cid-xf::security::desencrypt:

desEncrypt
----------


.. code-block:: cpp
	
	#include "xf_security/des.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desEncrypt (
	    ap_uint <64> in,
	    ap_uint <64> key,
	    ap_uint <64>& out
	    )

desEncrypt is the basic function for ciphering one block with one cipher key using DES



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - in

        - input one plain text to be encrypted, 64 bits.

    *
        - key

        - input cipher key, 64 bits.

    *
        - out

        - output encrypted text, 64 bits.

.. _doxid-namespacexf_1_1security_1ab0ebb58407aaac6f8086ddcbca29947f:
.. _cid-xf::security::desdecrypt:

desDecrypt
----------


.. code-block:: cpp
	
	#include "xf_security/des.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desDecrypt (
	    ap_uint <64> in,
	    ap_uint <64> cipherKey,
	    ap_uint <64>& out
	    )

desDecrypt is the basic function for decrypt one block with one cipher key using DES



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - in

        - input one encrypted text to be decrypted, 64 bits.

    *
        - cipherKey

        - input cipher key, 64 bits.

    *
        - out

        - output decrypted text, 64 bits.

.. _doxid-namespacexf_1_1security_1ab808290a69705afb297ed9bf2e551bff:
.. _cid-xf::security::des3encrypt:

des3Encrypt
-----------


.. code-block:: cpp
	
	#include "xf_security/des.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void des3Encrypt (
	    ap_uint <64> in,
	    ap_uint <64> key1,
	    ap_uint <64> key2,
	    ap_uint <64> key3,
	    ap_uint <64>& out
	    )

des3Encrypt is the basic function for ciphering one block with three cipher keys using 3DES



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - in

        - input one plain text to be encrypted, 64 bits.

    *
        - key1

        - input cipher key, 64 bits.

    *
        - key2

        - input cipher key, 64 bits.

    *
        - key3

        - input cipher key, 64 bits.

    *
        - out

        - output encrypted text, 64 bits.

.. _doxid-namespacexf_1_1security_1a5d5f67065902616b6c8fbafce4fc1fa1:
.. _cid-xf::security::des3decrypt:

des3Decrypt
-----------


.. code-block:: cpp
	
	#include "xf_security/des.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void des3Decrypt (
	    ap_uint <64> in,
	    ap_uint <64> key1,
	    ap_uint <64> key2,
	    ap_uint <64> key3,
	    ap_uint <64>& out
	    )

desDecrypt is the basic function for decrypt one block with three cipher keys using 3DES



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - in

        - input one encrypted text to be decrypted, 64 bits.

    *
        - key1

        - input cipher key, 64 bits.

    *
        - key2

        - input cipher key, 64 bits.

    *
        - key3

        - input cipher key, 64 bits.

    *
        - out

        - output decrypted text, 64 bits.

.. _doxid-namespacexf_1_1security_1af7be7cdf390d4c45bf1f6b57efe2b4f7:
.. _cid-xf::security::desecbencrypt:

desEcbEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desEcbEncrypt (
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

desEcbEncrypt is ECB encryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 64 bits for each key.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a6f8dbfa51ef386d6eda828529ac69de5:
.. _cid-xf::security::desecbdecrypt:

desEcbDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desEcbDecrypt (
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

desEcbDecrypt is ECB decryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 64 bits for each key.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a8fad538c40d5201f790fee2323d80851:
.. _cid-xf::security::aes128ecbencrypt:

aes128EcbEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128EcbEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128EcbEncrypt is ECB encryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a14b914daa46a22398c6015939ef6b913:
.. _cid-xf::security::aes128ecbdecrypt:

aes128EcbDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128EcbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128EcbDecrypt is ECB decryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a3636084af49deac6fc27b82d2e71334c:
.. _cid-xf::security::aes192ecbencrypt:

aes192EcbEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192EcbEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes192EcbEncrypt is ECB encryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a50e15b44ca27b306de9f3829db31374e:
.. _cid-xf::security::aes192ecbdecrypt:

aes192EcbDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192EcbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes192EcbDecrypt is ECB decryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1aef159af0edf79c1c29352c50edf98588:
.. _cid-xf::security::aes256ecbencrypt:

aes256EcbEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256EcbEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256EcbEncrypt is ECB encryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a58502cc465bb5bfaded03bd66db6d111:
.. _cid-xf::security::aes256ecbdecrypt:

aes256EcbDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ecb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256EcbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256EcbDecrypt is ECB decryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1ac6e4a18f7566a1de7e3f16a8e52db967:
.. _cid-xf::security::aes128gcmencrypt:

aes128GcmEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128GcmEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <96>>& IVStrm,
	    hls::stream <ap_uint <128>>& AADStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

aes128GcmEncrypt is GCM encryption mode with AES-128 single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - AADStrm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - tagStrm

        - The data tag

.. _doxid-namespacexf_1_1security_1a351432bccd1d3143257b84c23c74bba2:
.. _cid-xf::security::aes128gcmdecrypt:

aes128GcmDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128GcmDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <96>>& IVStrm,
	    hls::stream <ap_uint <128>>& AADStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

aes128GcmDecrypt is GCM decryption mode with AES-128 single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - AADStrm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - tagStrm

        - The data tag

.. _doxid-namespacexf_1_1security_1a23d877a87d12099c7dfbe34e2161c247:
.. _cid-xf::security::aes192gcmencrypt:

aes192GcmEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192GcmEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <96>>& IVStrm,
	    hls::stream <ap_uint <128>>& AADStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

aes192GcmEncrypt is GCM encryption mode with AES-192 single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - AADStrm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - tagStrm

        - The data tag

.. _doxid-namespacexf_1_1security_1a2b287e053f09032aeea5449e24dfe082:
.. _cid-xf::security::aes192gcmdecrypt:

aes192GcmDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192GcmDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <96>>& IVStrm,
	    hls::stream <ap_uint <128>>& AADStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

aes192GcmDecrypt is GCM decryption mode with AES-192 single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - AADStrm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - tagStrm

        - The data tag

.. _doxid-namespacexf_1_1security_1ae51d3eabebdbec9ee65e40d5f4ecb816:
.. _cid-xf::security::aes256gcmencrypt:

aes256GcmEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256GcmEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <96>>& IVStrm,
	    hls::stream <ap_uint <128>>& AADStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

aes256GcmEncrypt is GCM encryption mode with AES-256 single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - AADStrm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - tagStrm

        - The data tag

.. _doxid-namespacexf_1_1security_1a8e0508dcd73c25abee0659eb56880fa7:
.. _cid-xf::security::aes256gcmdecrypt:

aes256GcmDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/gcm.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256GcmDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <96>>& IVStrm,
	    hls::stream <ap_uint <128>>& AADStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

aes256GcmDecrypt is GCM decryption mode with AES-256 single block cipher.

The algorithm reference is : "IEEE Standard for Authenticated Encryption with Length Expansion for Storage Devices" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - AADStrm

        - Additional authenticated data for calculating the tag, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - tagStrm

        - The data tag

.. _doxid-namespacexf_1_1security_1ac42e1407fa37a17c4b2c88683fe47fdf:
.. _cid-xf::security::aes256gmac:

aes256Gmac
----------


.. code-block:: cpp
	
	#include "xf_security/gmac.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256Gmac (
	    hls::stream <ap_uint <128>>& dataStrm,
	    hls::stream <bool>& eDataStrm,
	    hls::stream <ap_uint <256>>& keyStrm,
	    hls::stream <ap_uint <96>>& ivStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

aes256Gmac is the basic encryption mode of AES-256.

Galois Message Authentication Code (GMAC) is a mechanism to provide data origin authentication.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - dataStrm

        - is input stream text to be authenticated, 128 bits.

    *
        - eDataStrm

        - is end flag of stream data, 1 bit.

    *
        - keyStrm

        - is input key used in encryption, 256 bits for AES-256.

    *
        - ivStrm

        - is initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - tagStrm

        - is the data tag

.. _doxid-namespacexf_1_1security_1a5405eced476b6783c0ef7517395fbe6e:
.. _cid-xf::security::hmac:

hmac
----


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
	void hmac (
	    hls::stream <ap_uint <keyW>>& keyStrm,
	    hls::stream <ap_uint <lW>>& keyLenStrm,
	    hls::stream <ap_uint <msgW>>& msgStrm,
	    hls::stream <ap_uint <lW>>& lenStrm,
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

.. _doxid-namespacexf_1_1security_1ae3fb57b80e5370f7050dfa02d3bbd2cd:
.. _cid-xf::security::md4:

md4
---


.. code-block:: cpp
	
	#include "xf_security/md4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void md4 (
	    hls::stream <ap_uint <32>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <128>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

Top of MD4.

The algorithm reference is : "The MD4 Message-Digest Algorithm".



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
        - digest_strm

        - The digest (fingerprint) stream.

    *
        - end_digest_strm

        - Flag to signal the end of the result.

.. _doxid-namespacexf_1_1security_1a4e0c0530f24ce90acd6b5eaa57b72b9b:
.. _cid-xf::security::md5:

md5
---


.. code-block:: cpp
	
	#include "xf_security/md5.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void md5 (
	    hls::stream <ap_uint <32>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <128>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

Top of MD5.

The algorithm reference is : "The MD5 Message-Digest Algorithm".



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
        - digest_strm

        - The digest (fingerprint) stream.

    *
        - end_digest_strm

        - Flag to signal the end of the result.

.. _doxid-namespacexf_1_1security_1a7705af5971e39b7d100b1badcafeffb5:
.. _cid-xf::security::desofbencrypt:

desOfbEncrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desOfbEncrypt (
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

desOfbEncrypt is OFB encryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES encrypition, 64 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1aab0b8d383316fcb199e2f0ebcdc85f48:
.. _cid-xf::security::desofbdecrypt:

desOfbDecrypt
-------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void desOfbDecrypt (
	    hls::stream <ap_uint <64>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& cipherkeyStrm,
	    hls::stream <ap_uint <64>>& IVStrm,
	    hls::stream <ap_uint <64>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

desOfbDecrypt is OFB decryption mode with DES single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 64 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 64 bits for each key.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of DES decrypition, 64 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 64 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a34c5576ce84ea97f854dc73366c4ddfa:
.. _cid-xf::security::aes128ofbencrypt:

aes128OfbEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128OfbEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128OfbEncrypt is OFB encryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a0b55cc09719a565ebfd26fd845ab5f0d:
.. _cid-xf::security::aes128ofbdecrypt:

aes128OfbDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128OfbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128OfbDecrypt is OFB decryption mode with AES-128 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1ad3d626195e50943b4486d9c7064196b9:
.. _cid-xf::security::aes192ofbencrypt:

aes192OfbEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192OfbEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes192OfbEncrypt is OFB encryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a64063f9dfb545f88963f8ca131cc651e:
.. _cid-xf::security::aes192ofbdecrypt:

aes192OfbDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes192OfbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <192>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes192OfbDecrypt is OFB decryption mode with AES-192 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 192 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a0d7b2182146497a9a3034e1de2f14e95:
.. _cid-xf::security::aes256ofbencrypt:

aes256OfbEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256OfbEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256OfbEncrypt is OFB encryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a201d4bec77f490fb384dca4dff2be0f3:
.. _cid-xf::security::aes256ofbdecrypt:

aes256OfbDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/ofb.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256OfbDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256OfbDecrypt is OFB decryption mode with AES-256 single block cipher.

The algorithm reference is : "Recommendation for Block Cipher Modes of Operation - Methods and Techniques" The implementation is modified for better performance.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - cipherkeyStrm

        - Input cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES decrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1a98647f42dfc8ee197b9395eaf65d7819:
.. _cid-xf::security::poly1305:

poly1305
--------


.. code-block:: cpp
	
	#include "xf_security/poly1305.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	void poly1305 (
	    hls::stream <ap_uint <256>>& keyStrm,
	    hls::stream <ap_uint <128>>& payloadStrm,
	    hls::stream <ap_uint <64>>& lenPldStrm,
	    hls::stream <bool>& endLenStrm,
	    hls::stream <ap_uint <128>>& tagStrm
	    )

The poly1305 takes a 32-byte one-time key and a message and produces a 16-byte tag. This tag is used to authenticate the message.



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

.. _doxid-namespacexf_1_1security_1a9f63a3d179dd50b6b84fa8f5842590c5:
.. _cid-xf::security::rc4:

rc4
---


.. code-block:: cpp
	
	#include "xf_security/rc4.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void rc4 (
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

.. _doxid-namespacexf_1_1security_1aad113f7845eb17d7812e4dc16665236b:
.. _cid-xf::security::sha1:

sha1
----


.. code-block:: cpp
	
	#include "xf_security/sha1.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void sha1 (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <5*w>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

Top of SHA-1.

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The implementation dataflows the pre-processing part and message digest part.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of each input message word, default value is 32.

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

.. _doxid-namespacexf_1_1security_1a30423c771a46078121605392a02e34b4:
.. _cid-xf::security::sha224:

sha224
------


.. code-block:: cpp
	
	#include "xf_security/sha224_256.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <int m_width>
	void sha224 (
	    hls::stream <ap_uint <m_width>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <224>>& hash_strm,
	    hls::stream <bool>& end_hash_strm
	    )

SHA-224 algorithm with ap_uint stream input and output.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - m_width

        - the input message stream width, currently only 32 allowed.

    *
        - msg_strm

        - the message being hashed.

    *
        - len_strm

        - the length message being hashed.

    *
        - end_len_strm

        - the flag for end of message length input.

    *
        - hash_strm

        - the result.

    *
        - end_hash_strm

        - the flag for end of hash output.

.. _doxid-namespacexf_1_1security_1a33cc66115d0656dc718e3c25bc462ee9:
.. _cid-xf::security::sha256:

sha256
------


.. code-block:: cpp
	
	#include "xf_security/sha224_256.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <int m_width>
	void sha256 (
	    hls::stream <ap_uint <m_width>>& msg_strm,
	    hls::stream <ap_uint <64>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <256>>& hash_strm,
	    hls::stream <bool>& end_hash_strm
	    )

SHA-256 algorithm with ap_uint stream input and output.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - m_width

        - the input message stream width, currently only 32 allowed.

    *
        - msg_strm

        - the message being hashed.

    *
        - len_strm

        - the length message being hashed.

    *
        - end_len_strm

        - the flag for end of message length input.

    *
        - hash_strm

        - the result.

    *
        - end_hash_strm

        - the flag for end of hash output.

.. _doxid-namespacexf_1_1security_1afc6fde65befdedeccc4bcb733dd5c8c8:
.. _cid-xf::security::sha3_224:

sha3_224
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void sha3_224 (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <224>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

Top of SHA3-224.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a67c79bc64f8ddabcc9a11de3c43f764f:
.. _cid-xf::security::sha3_256:

sha3_256
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void sha3_256 (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <256>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

Top of SHA3-256.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a2945aee1cfda81c251c8bceea10f93b6:
.. _cid-xf::security::sha3_384:

sha3_384
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void sha3_384 (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <384>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

Top of SHA3-384.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a58848d055ddfa297f2b3c3f17c9b8ac5:
.. _cid-xf::security::sha3_512:

sha3_512
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void sha3_512 (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <512>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

Top of SHA3-512.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a513f7f392e1f7f8cda8c9f9c189965e2:
.. _cid-xf::security::shake128:

shake128
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void shake128 (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <128>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

Top of SHAKE-128.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1a0b859e7cbb27dcd0117298e2c2cd49cb:
.. _cid-xf::security::shake256:

shake256
--------


.. code-block:: cpp
	
	#include "xf_security/sha3.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void shake256 (
	    hls::stream <ap_uint <64>>& msgStrm,
	    hls::stream <ap_uint <128>>& msgLenStrm,
	    hls::stream <bool>& endMsgLenStrm,
	    hls::stream <ap_uint <256>>& digestStrm,
	    hls::stream <bool>& endDigestStrm
	    )

Top of SHAKE-256.

The algorithm reference is : "SHA-3 Standard : Permutation-Based Hash and Extendable-Output Functions".



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

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

.. _doxid-namespacexf_1_1security_1af5f670b509db52ecc46c5cb45be0e53a:
.. _cid-xf::security::sha384:

sha384
------


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void sha384 (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <128>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <384>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

SHA-384 algorithm with stream input and output.

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The implementation dataflows the pre-processing part and message digest part.



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
        - digest_strm

        - Output digest stream.

    *
        - end_digest_strm

        - End flag for output digest stream.

.. _doxid-namespacexf_1_1security_1a61a521d4ac7e9120db1952e3cc7df13e:
.. _cid-xf::security::sha512:

sha512
------


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <unsigned int w>
	void sha512 (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <128>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <512>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

SHA-512 algorithm with stream input and output.

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The implementation dataflows the pre-processing part and message digest part.



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
        - digest_strm

        - Output digest stream.

    *
        - end_digest_strm

        - End flag for output digest stream.

.. _doxid-namespacexf_1_1security_1a9f95e3168b8ca4eb9c6e6cb9af1b1a1c:
.. _cid-xf::security::sha512_t:

sha512_t
--------


.. code-block:: cpp
	
	#include "xf_security/sha512_t.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    unsigned int w,
	    unsigned int t
	    >
	void sha512_t (
	    hls::stream <ap_uint <w>>& msg_strm,
	    hls::stream <ap_uint <128>>& len_strm,
	    hls::stream <bool>& end_len_strm,
	    hls::stream <ap_uint <t>>& digest_strm,
	    hls::stream <bool>& end_digest_strm
	    )

SHA-512/t algorithm with stream input and output.

The algorithm reference is : "Secure Hash Standard", which published by NIST in February 2012. The implementation dataflows the pre-processing part and message digest part.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - w

        - The bit width of each input message word, default value is 64.

    *
        - t

        - The bit width of the digest which depends on specific algorithm, typically is 224 or 256.

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

.. _doxid-namespacexf_1_1security_1a2348276c53da93cc692e02d68bca8e96:
.. _cid-xf::security::aes128xtsencrypt:

aes128XtsEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/xts.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128XtsEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& lenStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes128XtsEncrypt is XTS encryption mode with AES-128 single block cipher.

The algorithm reference is : "IEEE Standard for Cryptographic Protection of
Data on Block-Oriented Storage Devices" The implementation is optimized for better performance in FPGA.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - lenStrm

        - Total length of plaintext in bit, 64 bits.

    *
        - cipherkeyStrm

        - Input two cipher key used in encryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, 128 bits.

    *
        - endCiphertextStrm

        - End flag of stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1a2c307e84e9405be7579fffdfa55fe898:
.. _cid-xf::security::aes128xtsdecrypt:

aes128XtsDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/xts.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes128XtsDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& lenStrm,
	    hls::stream <ap_uint <128>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes128XtsDecrypt is XTS decryption mode with AES-128 single block cipher.

The algorithm reference is : "IEEE Standard for Cryptographic Protection of
Data on Block-Oriented Storage Devices" The implementation is optimized for better performance in FPGA.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - lenStrm

        - Total length of plaintext in bit, 64 bits.

    *
        - cipherkeyStrm

        - Input two cipher key used in decryption, 128 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

.. _doxid-namespacexf_1_1security_1aa19f90be317a49e6e04c469f93591f8a:
.. _cid-xf::security::aes256xtsencrypt:

aes256XtsEncrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/xts.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256XtsEncrypt (
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm,
	    hls::stream <ap_uint <64>>& lenStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm
	    )

aes256XtsEncrypt is XTS encryption mode with AES-256 single block cipher.

The algorithm reference is : "IEEE Standard for Cryptographic Protection of
Data on Block-Oriented Storage Devices" The implementation is optimized for better performance in FPGA.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - plaintextStrm

        - Input block stream text to be encrypted, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

    *
        - lenStrm

        - Total length of plaintext in bit, 64 bits.

    *
        - cipherkeyStrm

        - Input two cipher key used in encryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - ciphertextStrm

        - Output encrypted block stream text, 128 bits.

    *
        - endCiphertextStrm

        - End flag of stream ciphertext, 1 bit.

.. _doxid-namespacexf_1_1security_1aa3fc81575a5babdfc58e5f09806c7568:
.. _cid-xf::security::aes256xtsdecrypt:

aes256XtsDecrypt
----------------


.. code-block:: cpp
	
	#include "xf_security/xts.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void aes256XtsDecrypt (
	    hls::stream <ap_uint <128>>& ciphertextStrm,
	    hls::stream <bool>& endCiphertextStrm,
	    hls::stream <ap_uint <64>>& lenStrm,
	    hls::stream <ap_uint <256>>& cipherkeyStrm,
	    hls::stream <ap_uint <128>>& IVStrm,
	    hls::stream <ap_uint <128>>& plaintextStrm,
	    hls::stream <bool>& endPlaintextStrm
	    )

aes256XtsDecrypt is XTS decryption mode with AES-256 single block cipher.

The algorithm reference is : "IEEE Standard for Cryptographic Protection of
Data on Block-Oriented Storage Devices" The implementation is optimized for better performance in FPGA.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ciphertextStrm

        - Input block stream text to be decrypted, each block is 128 bits.

    *
        - endCiphertextStrm

        - End flag of block stream ciphertext, 1 bit.

    *
        - lenStrm

        - Total length of plaintext in bit, 64 bits.

    *
        - cipherkeyStrm

        - Input two cipher key used in decryption, 256 bits.

    *
        - IVStrm

        - Initialization vector for the fisrt iteration of AES encrypition, 128 bits.

    *
        - plaintextStrm

        - Output decrypted block stream text, each block is 128 bits.

    *
        - endPlaintextStrm

        - End flag of block stream plaintext, 1 bit.

