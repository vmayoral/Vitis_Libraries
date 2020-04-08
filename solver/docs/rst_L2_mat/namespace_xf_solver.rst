.. index:: pair: namespace; solver
.. _doxid-namespacexf_1_1solver:
.. _cid-xf::solver:

namespace solver
================

.. toctree::
	:hidden:

	namespace_xf_solver_internal.rst
	namespace_xf_solver_internalgetrf.rst



.. _doxid-namespacexf_1_1solver_1a5caf13f50af104347f5d38641bcba07a:
.. _cid-xf::solver::geqrf:
.. _doxid-namespacexf_1_1solver_1a2e848bf2dcc7f70ae8577b8cac517ef7:
.. _cid-xf::solver::gesvdj_2d:
.. ref-code-block:: cpp
	:class: overview-code-block

	// namespaces

	namespace :ref:`xf::solver::internal<doxid-namespacexf_1_1solver_1_1internal>`
	namespace :ref:`xf::solver::internalgetrf<doxid-namespacexf_1_1solver_1_1internalgetrf>`


.. FunctionSection




.. _doxid-namespacexf_1_1solver_1ad20787b69560c5ca2a142826bc697a43:
.. _cid-xf::solver::geqrf-2:

geqrf
-----


geqrf overload (1)
++++++++++++++++++


.. code-block:: cpp
	
	#include "MatrixDecomposition/geqrf.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NRMAX,
	    int NCMAX,
	    int NCU
	    >
	int geqrf (
	    int m,
	    int n,
	    T* A,
	    int lda,
	    T* tau
	    )

This function computes QR decomposition of matrix :math:`A`



.. math::

    \begin{equation*} {A = Q R}\end{equation*}

where :math:`A` is a dense matrix of size :math:`m \times n` , :math:`Q` is a :math:`m \times n` matrix with orthonormal columns, and :math:`R` is an upper triangular matrix.

The maximum matrix size supported in FPGA is templated by NRMAX and NCMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NRMAX

        - maximum number of rows of input matrix

    *
        - NCMAX

        - maximum number of columns of input matrix

    *
        - NCU

        - number of computation unit

    *
        - m

        - number of rows of matrix A

    *
        - n

        - number of cols of matrix A

    *
        - A

        - input matrix of size :math:`m \times lda` , and overwritten by the output triangular R matrix and min(m,n) elementary reflectors

    *
        - lda

        - leading dimension of matrix A

    *
        - tau

        - scalar factors for elementary reflectors

.. _doxid-namespacexf_1_1solver_1ab2657b17f70e04a8e4173d6f0b3d0661:
.. _cid-xf::solver::gesvdj:

gesvdj
------


.. code-block:: cpp
	
	#include "MatrixDecomposition/gesvdj.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void gesvdj (
	    int m,
	    T* A,
	    int lda,
	    T* S,
	    T* U,
	    int ldu,
	    T* V,
	    int ldv,
	    int& info
	    )

Symmetric Matrix Jacobi based Singular Value Decomposition (GESVDJ) .

.. math::

    \begin{equation*} {A = U \Sigma {V}^T}\end{equation*}

where :math:`A` is a dense symmetric matrix of size :math:`m \times m` , :math:`U` and :math:`V` are :math:`m \times m` matrix with orthonormal columns, and :math:`\Sigma` is diagonal matrix.

The maximum matrix size supported in FPGA is templated by NMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double).

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

        - input matrix of size :math:`m \times m`

    *
        - S

        - decomposed diagonal singular matrix of size :math:`m \times m`

    *
        - U

        - left U matrix of SVD

    *
        - V

        - right V matrix of SVD

    *
        - lda

        - leading dimension of matrix A

    *
        - ldu

        - leading dimension of matrix U

    *
        - ldv

        - leading dimension of matrix V

    *
        - info

        - output info (unused)

.. _doxid-namespacexf_1_1solver_1a09a9cf79325b1979afd55e16a07809db:
.. _cid-xf::solver::gesvj:

gesvj
-----


.. code-block:: cpp
	
	#include "MatrixDecomposition/gesvj.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NRMAX,
	    int NCMAX,
	    int MCU,
	    int NCU
	    >
	void gesvj (
	    int m,
	    int n,
	    T* A,
	    T* U,
	    T* S,
	    T* V
	    )

This function implements singular value decomposition of matrix A using one-sided Jacobi algorihtm.

.. math::

    \begin{equation*} {A = U \Sigma {V}^T}\end{equation*}

where :math:`A` is a dense matrix of size :math:`m \times n` , :math:`U` is :math:`m \times m` matrix with orthonormal columns, :math:`V` is :math:`n \times n` matrix with orthonormal columns, and :math:`\Sigma` is diagonal matrix.

The maximum matrix size supported in FPGA is templated by NCMAX, NRMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - 

    *
        - :

        - the data type of gesvj

    *
        - NRMAX

        - maximum number of rows of input matrix

    *
        - NCMAX

        - maximum number of columns of input matrix

    *
        - MCU

        - number of computation unit of M

    *
        - NCU

        - number of computation unit of N

    *
        - m

        - number of rows of matrix A

    *
        - n

        - number of cols of matrix A

    *
        - A

        - input matrix of size :math:`m \times n`

    *
        - S

        - decomposed diagonal singular matrix of size n

    *
        - U

        - left U matrix of SVD of size :math:`m \times m`

    *
        - V

        - right V matrix of SVD :math:`n \times n`

.. _doxid-namespacexf_1_1solver_1a499a10417278f4d2c8dd86f0d2efa045:
.. _cid-xf::solver::getrf:

getrf
-----


.. code-block:: cpp
	
	#include "MatrixDecomposition/getrf.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void getrf (
	    int n,
	    T* A,
	    int lda,
	    int* ipiv,
	    int& info
	    )

This function computes the LU decomposition (with partial pivoting) of matrix :math:`A`



.. math::

    \begin{equation*} {P A = L U}\end{equation*}

where :math:`P` is a permutation matrix, :math:`A` is a dense matrix of size :math:`n \times n` , :math:`L` is a lower triangular matrix with unit diagonal, and :math:`U` is an upper triangular matrix. This function does not implement pivoting.

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

        - input matrix, and overwritten by the output upper and lower triangular matrix

    *
        - lda

        - leading dimention of input matrix A

    *
        - pivot

        - indices, row i of matrix A is stored in row[i]

    *
        - info

        - output info (unused)

.. _doxid-namespacexf_1_1solver_1a8620e2ea1438eed2d5f042cff3463473:
.. _cid-xf::solver::getrf_nopivot:

getrf_nopivot
-------------


.. code-block:: cpp
	
	#include "MatrixDecomposition/getrf_nopivot.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void getrf_nopivot (
	    int n,
	    T* A,
	    int lda,
	    int& info
	    )

This function computes the LU decomposition (without pivoting) of matrix :math:`A`



.. math::

    \begin{equation*} {A = L U}\end{equation*}

where :math:`A` is a dense matrix of size :math:`n \times n` , :math:`L` is a lower triangular matrix with unit diagonal, and :math:`U` is an upper triangular matrix. This function does not implement pivoting.

The maximum matrix size supported in FPGA is templated by NMAX.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - T

        - data type (support float and double)

    *
        - NMAX

        - maximum number of rows/cols of input matrix

    *
        - NCU

        - number of computation unit

    *
        - n

        - number of rows/cols of matrix A

    *
        - A

        - input matrix

    *
        - lda

        - leading dimention of input matrix A

    *
        - info

        - output info (unused)

.. _doxid-namespacexf_1_1solver_1a86d85c78cb26ccbc608e10f2140c297b:
.. _cid-xf::solver::potrf:

potrf
-----


.. code-block:: cpp
	
	#include "MatrixDecomposition/potrf.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void potrf (
	    int m,
	    T* A,
	    int lda,
	    int& info
	    )

This function computes the Cholesky decomposition of matrix :math:`A`



.. math::

    \begin{equation*} {A = L {L}^T}\end{equation*}

where :math:`A` is a dense symmetric positive-definite matrix of size :math:`m \times m` , :math:`L` is a lower triangular matrix, and :math:`{L}^T` is the transposed matrix of :math:`L` .

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

        - input matrix of size :math:`m \times m`

    *
        - lda

        - leading dimention of input matrix A

    *
        - info

        - output info (unused)

