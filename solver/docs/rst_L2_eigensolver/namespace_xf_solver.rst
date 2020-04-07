.. index:: pair: namespace; solver
.. _doxid-namespacexf_1_1solver:
.. _cid-xf::solver:

namespace solver
================

.. toctree::
	:hidden:



.. ref-code-block:: cpp
	:class: overview-code-block


.. FunctionSection




.. _doxid-namespacexf_1_1solver_1a3bce76e5bb20982327a6f075442c6694:
.. _cid-xf::solver::syevj:

syevj
-----


.. code-block:: cpp
	
	#include "EigenSolver/syevj.hpp"



.. ref-code-block:: cpp
	:class: title-code-block

	template <
	    typename T,
	    int NMAX,
	    int NCU
	    >
	void syevj (
	    int m,
	    T* A,
	    int lda,
	    T* S,
	    T* U,
	    int ldu,
	    int& info
	    )

Symmetric Matrix Jacobi based Eigenvalue Decomposition (SYEVJ) .

.. math::

    \begin{equation*} {A U = U \Sigma, }\end{equation*}

where :math:`A` is a dense symmetric matrix of size :math:`m \times m` , :math:`U` is a :math:`m \times m` matrix with orthonormal columns, each column of U is the eigenvector :math:`v_{i}` , and :math:`\Sigma` is diagonal matrix, which contains the eigenvalues :math:`\lambda_{i}` of matrix A.

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
        - lda

        - leading dimension of matrix A

    *
        - ldu

        - leading dimension of matrix U

    *
        - info

        - output info (unused)

