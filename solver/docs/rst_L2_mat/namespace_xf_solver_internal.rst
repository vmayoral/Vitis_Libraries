.. index:: pair: namespace; internal
.. _doxid-namespacexf_1_1solver_1_1internal:
.. _cid-xf::solver::internal:

namespace internal
==================

.. toctree::
	:hidden:

	union_xf_solver_internal_double_cast_new.rst
	union_xf_solver_internal_double_casting.rst
	class_xf_solver_internal_Trait.rst
	class_xf_solver_internal_Trait-2.rst
	class_xf_solver_internal_Trait-3.rst



.. _doxid-namespacexf_1_1solver_1_1internal_1ab475066dc031316e497529f93b97d5f0:
.. _cid-xf::solver::internal::updatecolumns:
.. _doxid-namespacexf_1_1solver_1_1internal_1a85ccdc709e29ef31c1aa5fe8869d1f9d:
.. _cid-xf::solver::internal::update:
.. _doxid-namespacexf_1_1solver_1_1internal_1aff9b5f09f8b827ab92dc510531cbeb5d:
.. _cid-xf::solver::internal::qrf:
.. _doxid-namespacexf_1_1solver_1_1internal_1a8f2c74edab5dcce8c56064e2f7667d55:
.. _cid-xf::solver::internal::jacobi_rotation_2x2:
.. _doxid-namespacexf_1_1solver_1_1internal_1a1ca13651365e8bea947adbe881fa58ee:
.. _cid-xf::solver::internal::swaptwo:
.. _doxid-namespacexf_1_1solver_1_1internal_1ab59a13abf1abdb093f910a7e398e37c3:
.. _cid-xf::solver::internal::genblockmat:
.. _doxid-namespacexf_1_1solver_1_1internal_1a6d652326ee528ec7c65cc90dad2ce2e1:
.. _cid-xf::solver::internal::unrollcol:
.. _doxid-namespacexf_1_1solver_1_1internal_1a3d88159b55830f71101cab45eccac82a:
.. _cid-xf::solver::internal::unrollrow:
.. _doxid-namespacexf_1_1solver_1_1internal_1a334605a19e2b0c7469eaa9c11ec54788:
.. _cid-xf::solver::internal::funcdataflow:
.. _doxid-namespacexf_1_1solver_1_1internal_1a7d478128921a3dedff0cf7a9f533dc32:
.. _cid-xf::solver::internal::jacobi_svd:
.. _doxid-namespacexf_1_1solver_1_1internal_1a53605494a76bd3399866aab6f8b94c23:
.. _cid-xf::solver::internal::jacobi_rotation_2x2-2:
.. _doxid-namespacexf_1_1solver_1_1internal_1a32c48bb9af32b234a539bd4137134b78:
.. _cid-xf::solver::internal::svd_and_conv:
.. _doxid-namespacexf_1_1solver_1_1internal_1aec7b9038db40f6d1759691e26304f41a:
.. _cid-xf::solver::internal::update_a:
.. _doxid-namespacexf_1_1solver_1_1internal_1a8d5fdee99a09aedcab394b72ed5fb519:
.. _cid-xf::solver::internal::update_v:
.. _doxid-namespacexf_1_1solver_1_1internal_1a9b9f081f0cef1df085a670b7b0e43808:
.. _cid-xf::solver::internal::update_av:
.. _doxid-namespacexf_1_1solver_1_1internal_1aa7fa46af494d5848625778515f85d8f6:
.. _cid-xf::solver::internal::rowupdate:
.. _doxid-namespacexf_1_1solver_1_1internal_1a893b086163868745116c1a13c8a4c5ca:
.. _cid-xf::solver::internal::getrf_nopivot_core:
.. _doxid-namespacexf_1_1solver_1_1internal_1a713f7b1a154f468f6fa30fde5bf679dd:
.. _cid-xf::solver::internal::chol_col:
.. _doxid-namespacexf_1_1solver_1_1internal_1adbd492e61179a13632fb32adef9f2497:
.. _cid-xf::solver::internal::chol_jj:
.. _doxid-namespacexf_1_1solver_1_1internal_1a61a8301dc333e7c780cb8c07bc98aeca:
.. _cid-xf::solver::internal::chol_col_wrapper:
.. _doxid-namespacexf_1_1solver_1_1internal_1a12123b06ac77e65ed299e6ad496c35f7:
.. _cid-xf::solver::internal::cholesky_core:
.. ref-code-block:: cpp
	:class: overview-code-block

	// unions

	union :ref:`double_cast_new<doxid-unionxf_1_1solver_1_1internal_1_1double__cast__new>` 
	union :ref:`double_casting<doxid-unionxf_1_1solver_1_1internal_1_1double__casting>` 

	// classes

	template <typename T>
	class :ref:`Trait<doxid-classxf_1_1solver_1_1internal_1_1_trait>` 

	template <>
	class :ref:`Trait <double><doxid-classxf_1_1solver_1_1internal_1_1_trait_3_01double_01_4>` 

	template <>
	class :ref:`Trait <float><doxid-classxf_1_1solver_1_1internal_1_1_trait_3_01float_01_4>` 


.. FunctionSection




.. _doxid-namespacexf_1_1solver_1_1internal_1aaad1b1f9b454fea8f64a604d56ebd667:
.. _cid-xf::solver::internal::calc_converge:

calc_converge
-------------


Defined in <MatrixDecomposition/gesvj.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <typename T>
	void calc_converge (
	    T alpha,
	    T beta,
	    T gamma,
	    hls::stream <T>& conv_strm
	    )

calc the converge of next sweep

.. _doxid-namespacexf_1_1solver_1_1internal_1a447445e5604edde6b38182fe3f892e81:
.. _cid-xf::solver::internal::read_and_gen_2x2:

read_and_gen_2x2
----------------


Defined in <MatrixDecomposition/gesvj.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NRMAX,
	    int NCMAX,
	    int MCU,
	    int ACUM
	    >
	void read_and_gen_2x2 (
	    T matA [MCU][ACUM][NCMAX],
	    T A_i [MCU][ACUM],
	    T A_j [MCU][ACUM],
	    int m,
	    int n,
	    int col_i,
	    int col_j,
	    hls::stream <T>& alpha_strm,
	    hls::stream <T>& beta_strm,
	    hls::stream <T>& gamma_strm
	    )

Read two columns of A into two seperate Bram.

.. _doxid-namespacexf_1_1solver_1_1internal_1a6216ac2686f5051779baadef57f76341:
.. _cid-xf::solver::internal::read_v_2cols:

read_V_2cols
------------


Defined in <MatrixDecomposition/gesvj.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NCMAX,
	    int NCU,
	    int ACUN
	    >
	void read_V_2cols (
	    T matV [NCU][ACUN][NCMAX],
	    T V_i [NCU][ACUN],
	    T V_j [NCU][ACUN],
	    int n,
	    int col_i,
	    int col_j
	    )

Read two columns (i and j) of V into two seperate Bram V_i[N] and V_j[N].

.. _doxid-namespacexf_1_1solver_1_1internal_1aa4917299c2fd454532267908e8f76944:
.. _cid-xf::solver::internal::read_to_2cols:

read_to_2cols
-------------


Defined in <MatrixDecomposition/gesvj.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NRMAX,
	    int NCMAX,
	    int MCU,
	    int ACUM,
	    int NCU,
	    int ACUN
	    >
	void read_to_2cols (
	    T matA [MCU][ACUM][NCMAX],
	    T matV [NCU][ACUN][NCMAX],
	    T A_i [MCU][ACUM],
	    T A_j [MCU][ACUM],
	    T V_i [NCU][ACUN],
	    T V_j [NCU][ACUN],
	    int m,
	    int n,
	    int col_i,
	    int col_j,
	    hls::stream <T>& alpha_strm,
	    hls::stream <T>& beta_strm,
	    hls::stream <T>& gamma_strm
	    )

read 2 columns(i and j) of data from A matrix and V matrix

