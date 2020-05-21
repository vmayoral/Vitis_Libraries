#!/bin/bash

script="$0"
abs_basename="$(readlink -f $(dirname $script))"
basename_basename=$(basename $(dirname $(dirname $(readlink -f $0))))
mkdir -p $4

io_updator() {
    echo "Copying updated files..."
    cp -rf L1/README.rst docs/source/L1/overview.rst
    cp -rf L2/demos/README.rst docs/source/L2/overview.rst
    cp -rf L3/README.rst docs/source/L3/overview.rst
    ls_files="$(git ls-files)"
    for f in $ls_files; do
        b_name=$(basename $(dirname $f))
        if [[ ($f == L2/demos/*/README.rst) ]]; then
            cp -rf $f docs/source/L2/$b_name.rst
            echo "cp -rf $f docs/source/L2/$b_name.rst"
        elif [[ ($f == L3/demos/*/README.rst) ]]; then
            cp -rf $f docs/source/L3/$b_name.rst
            echo "cp -rf $f docs/source/L2/$b_name.rst"
        fi
    done
}

cd ../../

if [ -d $2 ]; then rm -rf $2; fi
if [ -d $3 ]; then rm -rf $3; fi

echo "Beginning Automation..."
# Cloning Faas Tool Kit Repo
git clone https://gitenterprise.xilinx.com/$1/$3.git
# Sourcing tool kit script
source $3/setup.sh
# Cloning Vitis Compression Library
git clone https://gitenterprise.xilinx.com/$1/$2.git -b $5

#echo "Getting Setup Ready..."
cp -rf $3/share/themes/Sphinx_Xilinx_Template/_ext/ $2/docs/
cp -rf $3/share/themes/Sphinx_Xilinx_Template/_themes/ $2/docs/
cp -rf $3/share/themes/Sphinx_Xilinx_Template/_templates/ $2/docs/
cd $2/docs

echo "Setting ENV variables..."
export PROJ_PATH=`pwd`/../
export HTML_DEST_DIR=`pwd`/../../$basename_basename/$2/$4/
export PATH=$PATH\:/usr/share/

while true; do
    read -p "Do you wish to update the IO pages?" yn
    case $yn in
        [Yy]* ) cd ..; io_updator; cd docs; make all; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done

cd ../../
rm -rf $2 $3
cd $abs_basename
cp -rf $4/docs $4/source/L2/
echo "Documentation can be review by opening index.html"
