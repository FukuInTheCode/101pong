#!/bin/bash

range=$1

# Test command with arguments in a certain range
for x0 in $(seq 1 $range)
do
    for y0 in $(seq -$range $range)
    do
        for z0 in $(seq -$range $range)
        do
            for x1 in $(seq -$range $range)
            do
                for y1 in $(seq -$range $range)
                do
                    for z1 in $(seq -$range $range)
                    do
                        for n in $(seq -$range $range)
                        do
                            echo "Running 101pong with the following arguments: "
                            echo "x0: $x0, y0: $y0, z0: $z0, x1: $x1, y1: $y1, z1: $z1, n: $n"

                            ../101pong $x0 $y0 $z0 $x1 $y1 $z1 $n | tail -1
                        done
                    done
                done
            done
        done
    done
done
