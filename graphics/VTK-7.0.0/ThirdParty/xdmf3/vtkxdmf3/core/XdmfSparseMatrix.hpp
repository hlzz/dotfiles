/*****************************************************************************/
/*                                    XDMF                                   */
/*                       eXtensible Data Model and Format                    */
/*                                                                           */
/*  Id : XdmfSparseMatrix.hpp                                                */
/*                                                                           */
/*  Author:                                                                  */
/*     Kenneth Leiter                                                        */
/*     kenneth.leiter@arl.army.mil                                           */
/*     US Army Research Laboratory                                           */
/*     Aberdeen Proving Ground, MD                                           */
/*                                                                           */
/*     Copyright @ 2011 US Army Research Laboratory                          */
/*     All Rights Reserved                                                   */
/*     See Copyright.txt for details                                         */
/*                                                                           */
/*     This software is distributed WITHOUT ANY WARRANTY; without            */
/*     even the implied warranty of MERCHANTABILITY or FITNESS               */
/*     FOR A PARTICULAR PURPOSE.  See the above copyright notice             */
/*     for more information.                                                 */
/*                                                                           */
/*****************************************************************************/

#ifndef XDMFSPARSEMATRIX_HPP_
#define XDMFSPARSEMATRIX_HPP_

// Includes
#include "XdmfCore.hpp"
#include "XdmfArray.hpp"

/**
 * @brief Sparse matrix implemented as compressed row storage.
 *
 * An XdmfSparseMatrix provides routines for interacting with a sparse
 * matrix.  It is stored internally in compressed row storage.
 */
class XDMFCORE_EXPORT XdmfSparseMatrix : public XdmfItem {

public:

  /**
   * Create a new XdmfSparseMatrix.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   *
   * @param     numberRows      Number of rows in matrix.
   * @param     numberColumns   Number of columns in matrix.
   *
   * @return                    Constructed XdmfSparseMatrix.
   */
  static shared_ptr<XdmfSparseMatrix> New(const unsigned int numberRows,
                                          const unsigned int numberColumns);

  virtual ~XdmfSparseMatrix();

  LOKI_DEFINE_VISITABLE(XdmfSparseMatrix, XdmfItem)
  static const std::string ItemTag;

  /**
   * Get the column index array.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setColumnIndex
   * @until //#setColumnIndex
   * @skipline //#getColumnIndex
   * @until //#getColumnIndex
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setColumnIndex
   * @until #//setColumnIndex
   * @skipline #//getColumnIndex
   * @until #//getColumnIndex
   *
   * @return    Array containing column indices for nonzero entries of
   *            matrix. This is the same size as values.
   */
  shared_ptr<XdmfArray> getColumnIndex();

  std::map<std::string, std::string> getItemProperties() const;

  std::string getItemTag() const;

  /**
   * Get the name of the sparse matrix.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setName
   * @until //#setName
   * @skipline //#getName
   * @until //#getName
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setName
   * @until #//setName
   * @skipline #//getName
   * @until #//getName
   *
   * @return    A string containing the name of the sparse matrix.
   */
  std::string getName() const;

  /**
   * Get the number of columns in the sparse matrix.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setColumnIndex
   * @until //#setColumnIndex
   * @skipline //#getNumberColumns
   * @until //#getNumberColumns
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setColumnIndex
   * @until #//setColumnIndex
   * @skipline #//getNumberColumns
   * @until #//getNumberColumns
   *
   * @return    The number of columns in the sparse matrix.
   */
  unsigned int getNumberColumns() const;

  /**
   * Get the number of rows in the sparse matrix.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setRowPointer
   * @until //#setRowPointer
   * @skipline //#getNumberRows
   * @until //#getNumberRows
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setRowPointer
   * @until #//setRowPointer
   * @skipline #//getNumberRows
   * @until #//getNumberRows
   *
   * @return    The number of rows in the sparse matrix.
   */
  unsigned int getNumberRows() const;

  /**
   * Get the row pointer array.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setRowPointer
   * @until //#setRowPointer
   * @skipline //#getRowPointer
   * @until //#getRowPointer
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setRowPointer
   * @until #//setRowPointer
   * @skipline #//getRowPointer
   * @until #//getRowPointer
   *
   * @return    Array containing indices into column array for each
   *            row. This is the size of the number of rows in the matrix +
   *            1. The last value is the number of nonzero entries in the matrix
   */
  shared_ptr<XdmfArray> getRowPointer();

  /**
   * Get the values array.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setRowPointer
   * @until //#setRowPointer
   * @skipline //#setColumnIndex
   * @until //#setColumnIndex
   * @skipline //#setValues
   * @until //#setValues
   * @skipline //#getValues
   * @until //#getValues
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setRowPointer
   * @until #//setRowPointer
   * @skipline #//setColumnIndex
   * @until #//setColumnIndex
   * @skipline #//setValues
   * @until #//setValues
   * @skipline #//getValues
   * @until #//getValues
   *
   * @return    Array containing values of nonzero entries of matrix.
   */
  shared_ptr<XdmfArray> getValues();

  /**
   * Get values as a string in two dimensional format.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setRowPointer
   * @until //#setRowPointer
   * @skipline //#setColumnIndex
   * @until //#setColumnIndex
   * @skipline //#setValues
   * @until //#setValues
   * @skipline //#getValuesString
   * @until //#getValuesString
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setRowPointer
   * @until #//setRowPointer
   * @skipline #//setColumnIndex
   * @until #//setColumnIndex
   * @skipline #//setValues
   * @until #//setValues
   * @skipline #//getValuesString
   * @until #//getValuesString
   *
   * @return    Atring representation of matrix.
   */
  std::string getValuesString() const;

  /**
   * Set the column index array.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setColumnIndex
   * @until //#setColumnIndex
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setColumnIndex
   * @until #//setColumnIndex
   *
   * @param     columnIndex     Array containing column indices for nonzero
   *                            entries of matrix. This is the same size as values.
   */
  void setColumnIndex(const shared_ptr<XdmfArray> columnIndex);

  /**
   * Set the name of the sparse matrix.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setName
   * @until //#setName
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setName
   * @until #//setName
   *
   * @param     name    A string containing the name to set.
   */
  void setName(const std::string & name);

  /**
   * Set the row pointer array.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setRowPointer
   * @until //#setRowPointer
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setRowPointer
   * @until #//setRowPointer
   *
   * @param     rowPointer      Array containing indices into column array for
   *                            each row. This is the size of the number of rows in the matrix +
   *                            1. The last value is the number of nonzero entries in the matrix
   */
  void setRowPointer(const shared_ptr<XdmfArray> rowPointer);

  /**
   * Set the values array.
   *
   * Example of use:
   *
   * C++
   *
   * @dontinclude ExampleXdmfSparseMatrix.cpp
   * @skipline //#initialization
   * @until //#initialization
   * @skipline //#setRowPointer
   * @until //#setRowPointer
   * @skipline //#setColumnIndex
   * @until //#setColumnIndex
   * @skipline //#setValues
   * @until //#setValues
   *
   * Python
   *
   * @dontinclude XdmfExampleSparseMatrix.py
   * @skipline #//initialization
   * @until #//initialization
   * @skipline #//setRowPointer
   * @until #//setRowPointer
   * @skipline #//setColumnIndex
   * @until #//setColumnIndex
   * @skipline #//setValues
   * @until #//setValues
   *
   * @param     values  Array containing values of nonzero entries of
   *                    matrix.
   */
  void setValues(const shared_ptr<XdmfArray> values);

  virtual void traverse(const shared_ptr<XdmfBaseVisitor> visitor);

protected:

  XdmfSparseMatrix(const unsigned int numberRows,
                   const unsigned int numberColumns);

  virtual void
  populateItem(const std::map<std::string, std::string> & itemProperties,
               const std::vector<shared_ptr<XdmfItem> > & childItems,
               const XdmfCoreReader * const reader);

private:

  XdmfSparseMatrix(const XdmfSparseMatrix &);  // Not implemented.
  void operator=(const XdmfSparseMatrix &);  // Not implemented.

  shared_ptr<XdmfArray> mColumnIndex;
  std::string mName;
  unsigned int mNumberColumns;
  unsigned int mNumberRows;
  shared_ptr<XdmfArray> mRowPointer;
  shared_ptr<XdmfArray> mValues;
};

#ifdef _WIN32
#endif

#endif /* XDMFSPARSEMATRIX_HPP_ */
