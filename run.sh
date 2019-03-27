#/bin/bash

PROCESS_NAME="modbus_ssa"
SSA_DIR="SSA"
BIN_DIR="bin"
LOG_DIR="log"

mkdir -f $LOG_DIR
./$PROCESS_NAME/$SSA_DIR/run.sh
