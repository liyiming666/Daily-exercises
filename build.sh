#!/bin/bash

OUTER_IP_ADDR="http://220.249.12.134:8082"
PROCESS_NAME="modbus_ssagent"
SDK_DIR="SDK"
SSA_DIR="SSA"
BIN_DIR="bin"
CONFIG_DIR="conf"
BRANCH="modbus_ssa"

C8Y_LIB_PATH="/home/liym/workSmell/ssa_modbus/cumulocity-sdk-c"

#配置区分正式/测试环境
# 0：正式环境
# 1：测试环境
USE_CONTPIB=$1

mkdir -p $BRANCH && cd $BRANCH

ROOT_DIR=$(pwd)

mkdir -p backup

time=$(date "+%Y-%m-%d_%H:%M:%S")

if [ -d $BIN_DIR ]; then
	cd $ROOT_DIR/$BIN_DIR
	if [ -f $PROCESS_NAME ]; then
		mv -f $PROCESS_NAME $PROCESS_NAME$time
	fi
	cd $ROOT_DIR
else
	mkdir -p $BIN_DIR
fi

(cd $ROOT_DIR/$SSA_DIR && make clean && make release) 
cd $ROOT_DIR

if [ ! -d $SSA_DIR ]; then
	echo "$SSA_DIR not exist, clone..."
	git clone -b $BRANCH $OUTER_IP_ADDR/ssa/SSA.git
fi

RUN_SCRIPT=$ROOT_DIR/$SSA_DIR/run.sh
chmod 755 $RUN_SCRIPT
cp -rfP $RUN_SCRIPT $ROOT_DIR/bin 
(cd $ROOT_DIR/$SSA_DIR && make release C8Y_LIB_PATH=$C8Y_LIB_PATH USE_CONTRIB=$USE_CONTRIB) 
if [ ! -d $ROOT_DIR/$CONFIG_DIR ]; then 
	ln -sf $ROOT_DIR/$SSA_DIR/$CONFIG_DIR $ROOT_DIR 
fi 

cd $ROOT_DIR 
exit 0














	






