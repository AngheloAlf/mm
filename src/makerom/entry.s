.section .text

.align 4

.globl entrypoint
.type entrypoint, @function
entrypoint:
    .ent entrypoint, 0
    .frame $sp, 0, $ra

    la      $t0, _bootSegmentBssStart
# TODO: AVOID_UB
    la      $t1, _bootSegmentBssSize

.clear_bss:
    addi    $t1, $t1, -0x8
    sw      $zero, 0x0($t0)
    sw      $zero, 0x4($t0)
    addi    $t0, $t0, 0x8
    bnez    $t1, .clear_bss

.enter_program:
    la      $t2, bootproc
    lui     $sp, %hi(sBootStack+0x400)
    addiu   $sp, $sp, %lo(sBootStack+0x400)
    jr      $t2

.size entrypoint, . - entrypoint
.end entrypoint

.fill 0x60 - (. - entrypoint)
