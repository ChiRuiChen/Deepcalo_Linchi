#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/silencekugelee05/hls4ml/train_recommended_electron_models_for_hls4ml/Deepcalo_Linchi/myproject_prj/solution1/.autopilot/db/a.g.bc ${1+"$@"}
