.. index:: pair: namespace; internal
.. _doxid-namespacexf_1_1security_1_1internal:
.. _cid-xf::security::internal:

namespace internal
==================

.. toctree::
	:hidden:



.. ref-code-block:: cpp
	:class: overview-code-block


.. FunctionSection




.. _doxid-namespacexf_1_1security_1_1internal_1a576c552d09e6524457e08ba481d40236:
.. _cid-xf::security::internal::aesencrypt:

aesEncrypt
----------


.. code-block:: cpp
	
	#include "xf_security/aes.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <int W>
	static void aesEncrypt (
	    ap_uint <128> plaintext,
	    ap_uint <W> cipherkey,
	    ap_uint <128>& ciphertext
	    )

aesEncrypt is the basic function for ciphering one block with one cipher key



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - W

        - cipher key width

    *
        - plaintext

        - input one word plain text to be encrypted, 128 bits.

    *
        - cipherkey

        - input cipher key, W bits.

    *
        - ciphertext

        - output one word encrypted text, 128 bit.

.. _doxid-namespacexf_1_1security_1_1internal_1a964318b2374b08bbd23038ee9e5b1fe3:
.. _cid-xf::security::internal::aesdecrypt:

aesDecrypt
----------


.. code-block:: cpp
	
	#include "xf_security/aes.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <int W>
	static void aesDecrypt (
	    ap_uint <128> ciphertext,
	    ap_uint <W> cipherkey,
	    ap_uint <128>& plaintext
	    )

aesDecrypt is the basic function for decrypting one block with one cipher key



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - W

        - cipher key width

    *
        - ciphertext

        - input one word cipher text to be decrypted, 128 bits.

    *
        - plainkey

        - input plain key, W bits.

    *
        - plaintext

        - output one word encrypted text, 128 bit.

