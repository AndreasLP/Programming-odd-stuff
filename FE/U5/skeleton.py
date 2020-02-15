#!/usr/bin/env python2.7
import os
import sys

REG_Z          =  0
REG_PC         = 63

OP_LOAD_B      =  0
OP_LOAD_H      =  1
OP_LOAD_W      =  2
OP_STORE_B     =  4
OP_STORE_H     =  5
OP_STORE_W     =  6
OP_ADD         =  8
OP_MUL         =  9
OP_DIV         = 10
OP_NOR         = 11
OP_MOVI        = 16
OP_CMOV        = 18
OP_IN          = 24
OP_OUT         = 25
OP_READ        = 26
OP_WRITE       = 27
OP_HALT        = 31

MEM_SIZE = 0x100000
SECTOR_SIZE = 0x200
MASK_W = 0xffffffff

class U5(object):
  def __init__(self, disk):
    self.mem = bytearray(MEM_SIZE)
    self.disk = disk
    self.regs = [0] * 64
    # Read first disk sector
    self.disk_read(0, 0)
    self.run()

  def run(self):
    while self.spin:
      pass

  def disk_seek(self, sector):
    self.disk.seek(sector * SECTOR_SIZE, os.SEEK_SET)

  def disk_read(self, addr, sector):
    assert addr % SECTOR_SIZE == 0, 'alignment error (read)'
    self.disk_seek(sector)
    data = self.disk.read(SECTOR_SIZE)
    assert len(data) == SECTOR_SIZE, 'disk read error'
    self.mem[addr : addr + SECTOR_SIZE] = data

  def disk_write(self, addr, sector):
    # TODO: ...

  @property
  def spin(self):
    pc = self.regs[REG_PC]
    assert pc % 4 == 0, 'alignment error (PC)'

    # Read 32bit big endian word
    inst = \
      self.mem[pc    ] << 24 | \
      self.mem[pc + 1] << 16 | \
      self.mem[pc + 2] <<  8 | \
      self.mem[pc + 3]

    # Increment PC before instruction execution
    self.regs[REG_PC] += 4

    # Register 0 must always be zero
    self.regs[REG_Z] = 0

    # Get the operation code
    op = inst >> 27

    # Execute MOVI-type instruction
    if op == OP_MOVI:
      a = (inst >> 21) & 077
      i = (inst >>  5) & 0xffff
      s = (inst      ) & 037
      self.regs[a] = (i << s) & MASK_W

    # All other instructions follow the same format
    else:
      if op == OP_HALT:
        print(sys.stderr, 'HALTed')
        # Stop execution
        return False
      # TODO: ...
    # Keep running
    return True

if __name__ == '__main__':
  if len(sys.argv) != 2:
    print >>sys.stderr, 'usage: %s <disk>' % sys.argv[0]
    sys.exit(-1)
  U5(file(sys.argv[1], 'r+b'))
