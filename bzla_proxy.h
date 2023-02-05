#pragma once

#include <bitwuzla.h>
#include <stdint.h>
#include <gmp.h>
#include <bzlabvstruct.h>

typedef struct BzlaBitVector BzlaBitVector;

#if __cplusplus
extern "C" {
#endif

	BzlaBitVector* bzla_node_bv_const_get_bits_proxy(BitwuzlaTerm* exp);

	uint32_t bzla_bv_get_width_proxy(const BzlaBitVector* bv);

	uint64_t bzla_bv_to_uint64_proxy(const BzlaBitVector* bv);

	uint32_t bzla_bv_get_bit_proxy(const BzlaBitVector* bv, uint32_t pos);

	void* bitwuzla_get_bzla_proxy(Bitwuzla* bitwuzla);

	void* bzla_node_fp_const_get_fp_proxy(BitwuzlaTerm* exp);

	BzlaBitVector* bzla_fp_as_bv_proxy(void* bzla, void* fp);

#if __cplusplus
}
#endif


/**
* Function from bzlanode.h
* 
 * Get the bit-vector representation of a bit-vector constant node.
 *
 * Bit-vector constants are normalized to LSB = 0. As a consequence, bit-vector
 * constant nodes can be inverted. This function returns the *real* bit-vector
 * representation of a bit-vector constant node, i.e., if it is inverted, it
 * returns the correctly inverted bit-vector representation. For example,
 * bit-vector constant '001' is represented as an inverted node 'n' that
 * represents '110', i.e., bzla_node_is_inverted(n) = true and n->bits = '110'.
 * This function will return '001' for 'n'.
 *
 * Note: The returned BzlaBitVector does not have to be freed.
 */
BzlaBitVector* bzla_node_bv_const_get_bits(BitwuzlaTerm* exp);

/** Get the bit-width of given bit-vector. */
uint32_t bzla_bv_get_width(const BzlaBitVector* bv);

/** Convert given bit-vector to an unsigned 64 bit integer. */
uint64_t bzla_bv_to_uint64(const BzlaBitVector* bv);

/** Get value of bit at given index (index 0 is LSB, width - 1 is MSB). */
uint32_t bzla_bv_get_bit(const BzlaBitVector* bv, uint32_t pos);

void* bitwuzla_get_bzla(Bitwuzla* bitwuzla);

/**
 * Get the floating-point representation of a floating-point constant node.
 * Note: The returned BzlaFloatingPoint does not have to be freed.
 */
void* bzla_node_fp_const_get_fp(BitwuzlaTerm* exp);

/** Get the bit-vector representing a given floating-point.  */
BzlaBitVector* bzla_fp_as_bv(void* bzla, void* fp);