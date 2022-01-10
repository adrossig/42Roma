#!/bin/bash

LOG_FILE="pip_install.log"
PYTHON_PATH="/usr/bin/python3"
VENE_DIR=".venv"

# setup venv
$PYTHON_PATH -m venv $VENE_DIR
source $VENE_DIR/bin/activate

# pip version
pip --version

# pip install
pip install --force-reinstall -r requirements.txt
