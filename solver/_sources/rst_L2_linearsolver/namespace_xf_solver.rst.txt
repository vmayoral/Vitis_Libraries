.. index:: pair: namespace; solver
.. _doxid-namespacexf_1_1solver:
.. _cid-xf::solver:

namespace solver
================

.. toctree::
	:hidden:

	namespace_xf_solver_internal.rst
	namespace_xf_solver_internal_gelinear.rst
	namespace_xf_solver_internal_gemi.rst
	namespace_xf_solver_internal_polinear.rst
	namespace_xf_solver_internal_pomi.rst
	namespace_xf_solver_internal_trtrs.rst



.. ref-code-block:: cpp
	:class: overview-code-block

	// namespaces

	namespace :ref:`xf::solver::internal<doxid-namespacexf_1_1solver_1_1internal>`
	namespace :ref:`xf::solver::internal_gelinear<doxid-namespacexf_1_1solver_1_1internal__gelinear>`
	namespace :ref:`xf::solver::internal_gemi<doxid-namespacexf_1_1solver_1_1internal__gemi>`
	namespace :ref:`xf::solver::internal_polinear<doxid-namespacexf_1_1solver_1_1internal__polinear>`
	namespace :ref:`xf::solver::internal_pomi<doxid-namespacexf_1_1solver_1_1internal__pomi>`
	namespace :ref:`xf::solver::internal_trtrs<doxid-namespacexf_1_1solver_1_1internal__trtrs>`


.. FunctionSection




.. _doxid-namespacexf_1_1solver_1a4380dbd7992efd603fe32bf2a3415df9:
.. _cid-xf::solver::gelinearsolver:

gelinearsolver
--------------


Defined in <LinearSolver/gelinearsolver.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void gelinearsolver (
	    int n,
	    T* A,
	    int b,
	    T* B,
	    int lda,
	    int ldb,
	    int& info
	    )

This function solves a system of linear equation with general matrix along with multiple right-hand side vector



.. math::

    \begin{equation*} {Ax=B}\end{equation*}

where :math:`A` is a dense general matrix of size :math:`n \times n` , :math:`x` is a vector need to be computed, and :math:`B` is input vector.

The maximum matrix size supported in FPGA is templated by NMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NMAX

        - maximum number of rows/columns of input matrix

    *
        - NCU

        - number of computation unit

    *
        - n

        - number of rows/cols of matrix A

    *
        - A

        - input matrix of size :math:`n \times n`

    *
        - b

        - number of columns of matrix B

    *
        - B

        - input matrix of size :math:`b \times n` , and overwritten by the output matrix x

    *
        - lda

        - leading dimention of input matrix A

    *
        - ldb

        - leading dimention of input matrix B

    *
        - info

        - output info (unused)

.. _doxid-namespacexf_1_1solver_1a330738ad0c91400601fc9029bbe18d70:
.. _cid-xf::solver::gematrixinverse:

gematrixinverse
---------------


Defined in <LinearSolver/gematrixinverse.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void gematrixinverse (
	    int m,
	    T* A,
	    int lda,
	    int& info
	    )

This function computes the inverse matrix of :math:`A`



.. math::

    \begin{equation*} {A}^{-1}\end{equation*}

where :math:`A` is a dense general matrix of size :math:`m \times m` . The maximum matrix size supported in FPGA is templated by NMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NMAX

        - maximum number of rows/columns of input matrix

    *
        - NCU

        - number of computation unit

    *
        - m

        - number of rows/cols of matrix A

    *
        - A

        - input matrix of size :math:`n \times n`

    *
        - lda

        - leading dimention of input matrix A

    *
        - info

        - output info (unused)

.. _doxid-namespacexf_1_1solver_1ab2a500c3d35adb231e4fbdfe7b17932a:
.. _cid-xf::solver::gtsv:

gtsv
----


Defined in <LinearSolver/gtsv_pcr.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    unsigned int NMAX,
	    unsigned int NCU
	    >
	int gtsv (
	    unsigned int n,
	    T* matDiagLow,
	    T* matDiag,
	    T* matDiagUp,
	    T* rhs
	    )

Tri-diagonal linear solver. Compute solution to linear system with a tridiagonal matrix. Parallel Cyclic Reduction method.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NMAX

        - matrix size

    *
        - NCU

        - number of compute units

    *
        - matDiagLow

        - lower diagonal of matrix

    *
        - matDiag

        - diagonal of matrix

    *
        - matDiagUp

        - upper diagonal of matrix

    *
        - rhs

        - right-hand side

.. _doxid-namespacexf_1_1solver_1ada1d0e10d79095ed587f0714b7d3b1d1:
.. _cid-xf::solver::polinearsolver:

polinearsolver
--------------


Defined in <LinearSolver/polinearsolver.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void polinearsolver (
	    int n,
	    T* A,
	    int b,
	    T* B,
	    int lda,
	    int ldb,
	    int& info
	    )

This function solves a system of linear equation with symmetric positive definite (SPD) matrix along with multiple right-hand side vector



.. math::

    \begin{equation*} {Ax=B}\end{equation*}

where :math:`A` is a dense SPD triangular matrix of size :math:`m \times m` , :math:`x` is a vector need to be computed, and :math:`B` is input vector.

The maximum matrix size supported in FPGA is templated by NMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NMAX

        - maximum number of rows/columns of input matrix

    *
        - NCU

        - number of computation unit

    *
        - n

        - number of rows/cols of matrix A

    *
        - A

        - input matrix of size :math:`n \times n`

    *
        - b

        - number of columns of matrix B

    *
        - B

        - input matrix of size :math:`b \times n` , and overwritten by the output matrix x

    *
        - lda

        - leading dimention of input matrix A

    *
        - ldb

        - leading dimention of input matrix B

    *
        - info

        - output info (unused)

.. _doxid-namespacexf_1_1solver_1a3b929dda3eb23cf26506eae627591870:
.. _cid-xf::solver::pomatrixinverse:

pomatrixinverse
---------------


Defined in <LinearSolver/pomatrixinverse.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void pomatrixinverse (
	    int m,
	    T* A,
	    int lda,
	    int& info
	    )

This function computes the inverse matrix of :math:`A`



.. math::

    \begin{equation*} {A}^{-1}\end{equation*}

where :math:`A` is a dense symmetric positive-definite matrix of size :math:`m \times m` . The maximum matrix size supported in FPGA is templated by NMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NMAX

        - maximum number of rows/columns of input matrix

    *
        - NCU

        - number of computation unit

    *
        - m

        - number of rows/cols of matrix A

    *
        - A

        - input matrix of size :math:`n \times n`

    *
        - lda

        - leading dimention of input matrix A

    *
        - info

        - output info (unused)

.. _doxid-namespacexf_1_1solver_1a807c039392d453610093336dbb4b0b19:
.. _cid-xf::solver::trtrs:

trtrs
-----


Defined in <LinearSolver/trtrs.hpp>
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void trtrs (
	    char uplo,
	    int m,
	    T* A,
	    int b,
	    T* B,
	    int lda,
	    int ldb,
	    int& info
	    )

This function solves a system of linear equation with triangular coefficient matrix along with multiple right-hand side vector



.. math::

    \begin{equation*} {Ax=B}\end{equation*}

where :math:`A` is a dense lower or upper triangular matrix of size :math:`m \times m` , :math:`x` is a vector need to be computed, and :math:`B` is input vector.

The maximum matrix size supported in FPGA is templated by NMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NMAX

        - maximum number of rows/columns of input matrix

    *
        - NCU

        - number of computation unit

    *
        - m

        - number of rows/cols of matrix A

    *
        - A

        - input matrix of size :math:`n \times n`

    *
        - b

        - number of columns of matrix B

    *
        - B

        - input matrix of size :math:`b \times n` , and overwritten by the output matrix x

    *
        - lda

        - leading dimention of input matrix A

    *
        - ldb

        - leading dimention of input matrix B

    *
        - info

        - output info (unused)

