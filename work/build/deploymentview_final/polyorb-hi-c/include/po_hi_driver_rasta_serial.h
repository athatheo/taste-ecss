/*
 * This is a part of PolyORB-HI-C distribution, a minimal
 * middleware written for generated code from AADL models.
 * You should use it with the Ocarina toolsuite.
 *
 * For more informations, please visit http://www.openaadl.org
 *
 * Copyright (C) 2010-2019 ESA & ISAE, 2019-2020 OpenAADL
 */

#include <deployment.h>

#ifndef __PO_HI_DRIVER_RASTA_SERIAL_H__
#define __PO_HI_DRIVER_RASTA_SERIAL_H__

#ifdef __PO_HI_NEED_DRIVER_SERIAL_RASTA

void __po_hi_c_driver_serial_rasta_poller (const __po_hi_device_id dev_id);

void __po_hi_c_driver_serial_rasta_init (__po_hi_device_id id);

int __po_hi_c_driver_serial_rasta_sender (const __po_hi_task_id task_id, const __po_hi_port_t port);

#endif

#endif
