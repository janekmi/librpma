/*
 * Copyright 2019-2020, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *     * Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
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

/*
 * librpma.c -- entry points for librpma
 */

#include "out.h"
#include "util.h"

#include "librpma.h"
#include "rpma.h"

/*
 * librpma_init -- load-time initialization for librpma
 *
 * Called automatically by the run-time loader.
 */
ATTR_CONSTRUCTOR
void
librpma_init(void)
{
	util_init();
	out_init(RPMA_LOG_PREFIX, RPMA_LOG_LEVEL_VAR, RPMA_LOG_FILE_VAR,
		 RPMA_MAJOR_VERSION, RPMA_MINOR_VERSION);

	LOG(3, NULL);
	/* XXX possible rpma_init placeholder */
}

/*
 * librpma_fini -- librpma cleanup routine
 *
 * Called automatically when the process terminates.
 */
ATTR_DESTRUCTOR
void
librpma_fini(void)
{
	LOG(3, NULL);

	out_fini();
}

/*
 * rpma_errormsg -- return last error message
 */
const char *
rpma_errormsg(void)
{
	return out_get_errormsg();
}
