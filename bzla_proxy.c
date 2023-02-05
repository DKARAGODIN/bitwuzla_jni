#include <bitwuzla.h>
#include "bzla_proxy.h"

BzlaBitVector* bzla_node_bv_const_get_bits_proxy(BitwuzlaTerm* exp) {
	return bzla_node_bv_const_get_bits(exp);
}

uint32_t bzla_bv_get_width_proxy(const BzlaBitVector* bv) {
	return bzla_bv_get_width(bv);
}

uint64_t bzla_bv_to_uint64_proxy(const BzlaBitVector* bv) {
	return bzla_bv_to_uint64(bv);
}

uint32_t bzla_bv_get_bit_proxy(const BzlaBitVector* bv, uint32_t pos) {
	return bzla_bv_get_bit(bv, pos);
}

void* bitwuzla_get_bzla_proxy(Bitwuzla* bitwuzla) {
	return bitwuzla_get_bzla(bitwuzla);
}

void* bzla_node_fp_const_get_fp_proxy(BitwuzlaTerm* exp) {
	return bzla_node_fp_const_get_fp(exp);
}

BzlaBitVector* bzla_fp_as_bv_proxy(void* bzla, void* fp) {
	return bzla_fp_as_bv(bzla, fp);
}