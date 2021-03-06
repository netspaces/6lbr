/*
 * Copyright (c) 2015, CETIC.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * \file
 *         Header file for 6LBR Hooks
 * \author
 *         6LBR Team <6lbr@cetic.be>
 */

#ifndef SIXLBR_HOOKS_H_
#define SIXLBR_HOOKS_H_

#if CETIC_6LBR_WITH_RPL
#include "rpl-private.h"
#else
typedef void rpl_instance_t;
typedef void rpl_dag_t;
typedef void rpl_dio_t;
#endif

/*---------------------------------------------------------------------------*/

typedef int (*cetic_6lbr_allowed_node_hook_t) (rpl_dag_t *dag, uip_ipaddr_t *prefix, int prefix_len);

extern cetic_6lbr_allowed_node_hook_t cetic_6lbr_allowed_node_hook;

extern int cetic_6lbr_allowed_node_default_hook(rpl_dag_t *dag, uip_ipaddr_t *prefix, int prefix_len);

/*---------------------------------------------------------------------------*/

typedef int(*cetic_6lbr_dis_input_hook_t)(void);

extern cetic_6lbr_dis_input_hook_t cetic_6lbr_dis_input_hook;

extern int cetic_6lbr_dis_input_default_hook(void);

/*---------------------------------------------------------------------------*/

typedef int (*cetic_6lbr_dio_input_hook_t)(uip_ipaddr_t *from, rpl_instance_t *instance, rpl_dag_t *dag, rpl_dio_t *dio);

extern cetic_6lbr_dio_input_hook_t cetic_6lbr_dio_input_hook;

extern int cetic_6lbr_dio_input_default_hook(uip_ipaddr_t *from, rpl_instance_t *instance, rpl_dag_t *dag, rpl_dio_t *dio);

/*---------------------------------------------------------------------------*/

#endif
