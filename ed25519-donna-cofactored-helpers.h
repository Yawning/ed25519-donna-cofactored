/*
 * Copyright (c) 2009 The Go Authors. All rights reserved.
 * Copyright (c) 2020 Henry de Valence. All rights reserved.
 * Copyright (c) 2021 Yawning Angel. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following disclaimer
 *    in the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of Google Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

static void
ge25519_mul_by_cofactor(ge25519 *r, const ge25519 *p) {
	ge25519_p1p1 t0;
	ge25519 t1;

	ge25519_double_p1p1(&t0, p);
	ge25519_p1p1_to_full(&t1, &t0);
	ge25519_double_p1p1(&t0, &t1);
	ge25519_p1p1_to_full(&t1, &t0);
	ge25519_double_p1p1(&t0, &t1);
	ge25519_p1p1_to_full(r, &t0);
}

static void
ge25519_projected_to_extended(ge25519 *r, const ge25519 *p) {
	curve25519_mul(r->t, p->x, p->y);
	curve25519_mul(r->x, p->x, p->z);
	curve25519_mul(r->y, p->y, p->z);
	curve25519_square(r->z, p->z);
}
