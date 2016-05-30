#include <keystone/keystone.h>
int main(int argc, char **argv) {
  int ks_arch = KS_ARCH_X86, ks_mode = KS_MODE_64;
  unsigned char assembly[] = {
    '_', '-', '_', '*', '-', '_', '*', 'A', 'X', 0x0,
  };
  ks_engine *ks;
  ks_err err = ks_open(ks_arch, ks_mode, &ks);
  if (!err) {
    size_t count, size;
    unsigned char *insn;
    ks_asm(ks, (char *)assembly, 0, &insn, &size, &count);
    ks_free(insn);
  }
  ks_close(ks);
}