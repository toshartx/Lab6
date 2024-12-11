#!/bin/bash

PROJECT_NAME="Lab6"
PROJECT_ROOT=".."
BUILD_DIR="$PROJECT_ROOT/build"

if [ -e "$BUILD_DIR" ]; then
  echo "Удаление директории $BUILD_DIR..."
  rm -rf "$BUILD_DIR"
fi
# сборка
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit
cmake "$PROJECT_ROOT" 
make

cd "$PROJECT_ROOT" || exit

echo "Сборка $PROJECT_NAME завершена!"
echo "Исполняемый файл находится в директории executables/"