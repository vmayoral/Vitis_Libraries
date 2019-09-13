.. index:: pair: namespace; internal
.. _doxid-namespacexf_1_1security_1_1internal:
.. _cid-xf::security::internal:

namespace internal
==================

.. toctree::
	:hidden:



.. _doxid-namespacexf_1_1security_1_1internal_1aa207faaaefd24fcf1dbeb8027b040ea1:
.. _cid-xf::security::internal::permmap:
.. _doxid-namespacexf_1_1security_1_1internal_1a9b3e7abd47c20704dfe70e06a0219e4a:
.. _cid-xf::security::internal::ipermmap:
.. _doxid-namespacexf_1_1security_1_1internal_1a22d6c13d06629aa99cf78c3dfe802084:
.. _cid-xf::security::internal::extmap:
.. _doxid-namespacexf_1_1security_1_1internal_1a4a70a89514e3b4b1071e47643926b4bc:
.. _cid-xf::security::internal::sp:
.. _doxid-namespacexf_1_1security_1_1internal_1a480b0b2a8ca5c5dca9d7908c22b24c9f:
.. _cid-xf::security::internal::fpermmap:
.. _doxid-namespacexf_1_1security_1_1internal_1aafee4f536f80ea933ef27c2cf228d4d5:
.. _cid-xf::security::internal::pcmapc:
.. _doxid-namespacexf_1_1security_1_1internal_1a7f5887a3851ff642c737a07a0c7c8b3b:
.. _cid-xf::security::internal::pcmapd:
.. _doxid-namespacexf_1_1security_1_1internal_1a618f8ee526aaf779856dd72b19c4cea5:
.. _cid-xf::security::internal::pc2map:
.. _doxid-namespacexf_1_1security_1_1internal_1ae6d8c7068b7a9e91f171e850030261e3:
.. _cid-xf::security::internal::subkeyindex:
.. _doxid-namespacexf_1_1security_1_1internal_1ae7f958e343b6b4569a54b40f64b2ec73:
.. _cid-xf::security::internal::print:
.. _doxid-namespacexf_1_1security_1_1internal_1a59bd10fdfc50eec51e07152e9e45342e:
.. _cid-xf::security::internal::print-2:
.. _doxid-namespacexf_1_1security_1_1internal_1a3fc08762026284b9b07c50ae29a97814:
.. _cid-xf::security::internal::printarray:
.. _doxid-namespacexf_1_1security_1_1internal_1ab7fdb87f4700c36ad9c2d9a4968f912a:
.. _cid-xf::security::internal::convertendian:
.. _doxid-namespacexf_1_1security_1_1internal_1aa47565a8ef7fa4208200cc4a3812374b:
.. _cid-xf::security::internal::convert:
.. _doxid-namespacexf_1_1security_1_1internal_1ace786c0c4252b6c2302970961c48c0bf:
.. _cid-xf::security::internal::initsubkeycd:
.. _doxid-namespacexf_1_1security_1_1internal_1a3e89234f159cd663ae70aebfbe268fe9:
.. _cid-xf::security::internal::initsubkeyindex:
.. _doxid-namespacexf_1_1security_1_1internal_1a7e12c265157d35763e78e5ebbea23358:
.. _cid-xf::security::internal::leftrotateshiftarray:
.. _doxid-namespacexf_1_1security_1_1internal_1a034fdee07e4ff7ab18910949529df9da:
.. _cid-xf::security::internal::getsubkeyindex:
.. _doxid-namespacexf_1_1security_1_1internal_1a3b15fc24cd072345beefcfb52e015fc8:
.. _cid-xf::security::internal::leftrotateshift:
.. _doxid-namespacexf_1_1security_1_1internal_1a2c6a8ee5a0b2eded1c34f373451e2cf7:
.. _cid-xf::security::internal::getsubkey:
.. _doxid-namespacexf_1_1security_1_1internal_1a7990d98e33815b92702af7564de082d2:
.. _cid-xf::security::internal::extend:
.. _doxid-namespacexf_1_1security_1_1internal_1abd21d4a2f60410fb011255f136ff520b:
.. _cid-xf::security::internal::substitute:
.. _doxid-namespacexf_1_1security_1_1internal_1a302825b34cf28fedf9c15113370bbf52:
.. _cid-xf::security::internal::perm:
.. _doxid-namespacexf_1_1security_1_1internal_1a2c79ef2e09d2ce329aa13765737f66f0:
.. _cid-xf::security::internal::f:
.. _doxid-namespacexf_1_1security_1_1internal_1a342bfffc8e0d9e411bdd54e1d79f20fd:
.. _cid-xf::security::internal::initperm:
.. _doxid-namespacexf_1_1security_1_1internal_1a8e2b5924706b3291abae76e115258f1f:
.. _cid-xf::security::internal::finalperm:
.. _doxid-namespacexf_1_1security_1_1internal_1af9b4876f159ad444b1099ce425916480:
.. _cid-xf::security::internal::process:
.. _doxid-namespacexf_1_1security_1_1internal_1af9c374a862fcddd2fa2e8ed0359ff8e1:
.. _cid-xf::security::internal::keyindexschedule:
.. _doxid-namespacexf_1_1security_1_1internal_1a7f3b947579038787d0b257368f7305c6:
.. _cid-xf::security::internal::keyscheduleoriginal:
.. ref-code-block:: cpp
	:class: overview-code-block

	// global variables

	const ap_uint <8> PermMap[64]
	const ap_uint <8> IPermMap[64]
	const ap_uint <8> ExtMap[48]
	const ap_uint <4> SP[8][64]
	const ap_int <8> FPermMap[32]
	const ap_uint <8> PCMapC[28]
	const ap_uint <8> PCMapD[28]
	const ap_uint <8> PC2Map[48]
	const ap_uint <8> subkeyIndex[16][48]


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

.. _doxid-namespacexf_1_1security_1_1internal_1abafad92b08745206ea244df38e0dd1bf:
.. _cid-xf::security::internal::keyschedule:

keySchedule
-----------


.. code-block:: cpp
	
	#include "xf_security/des.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	static void keySchedule (
	    ap_uint <64> key,
	    ap_uint <48> subkeys [16]
	    )

keySchedule is to schedule subkeys used in DES and 3DES



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - key

        - input original key, 64 bits.

    *
        - subkeys

        - output subkeys in encryption or decryption.

