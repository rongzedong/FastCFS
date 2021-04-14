/*
 * Copyright (c) 2020 YuQing <384681@qq.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _AUTH_DAO_H
#define _AUTH_DAO_H

#include "../../server_global.h"
#include "types.h"
#include "user.h"

#ifdef __cplusplus
extern "C" {
#endif

extern uint64_t g_dao_session_id;  //for request FastDIR

static inline int dao_get_context_size()
{
    return sizeof(FDIRClientContext);
}

static inline int dao_init_context(void *ctx)
{
    int result;
    FDIRClientContext *client_ctx;

    client_ctx = (FDIRClientContext *)ctx;
    fcfs_auth_client_init_full_ctx(&client_ctx->auth);
    if ((result=fdir_client_simple_init_ex(client_ctx, g_server_global_vars.
                    fdir_client_cfg_filename, NULL)) != 0)
    {
        return result;
    }

    //TODO set session id directly
    return 0;
}

#ifdef __cplusplus
}
#endif

#endif
