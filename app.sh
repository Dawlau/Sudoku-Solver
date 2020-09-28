#! /usr/bin/bash

FILES=$(find . -name "*.cpp")

g++ $FILES -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

./app