#!/bin/bash

for file in ./*.asm; do
	mv "$file" "${file%.asm}.s"
done
