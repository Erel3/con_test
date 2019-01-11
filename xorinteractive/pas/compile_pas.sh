#!/bin/bash

TASK=xoractive

fpc -XS -O2 -o${TASK} grader.pas
