#!/bin/bash

for file in ./*.s; do
	mv "$file" "${file%.s}.asm"
done
