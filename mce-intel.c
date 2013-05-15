/*
 * Copyright (C) 2013 Mauro Carvalho Chehab <mchehab@redhat.com>
 *
 * The code below were adapted from Andi Kleen/Intel/SuSe mcelog code,
 * released under GNU Public General License, v.2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include <stdio.h>

#include "ras-mce-handler.h"

#define MCE_THERMAL_BANK	(MCE_EXTENDED_BANK + 0)
#define MCE_TIMEOUT_BANK        (MCE_EXTENDED_BANK + 90)

static char *bank_name(unsigned bank)
{
	static char buf[64];

	switch (bank) {
	case MCE_THERMAL_BANK:
		return "THERMAL EVENT";
	case MCE_TIMEOUT_BANK:
		return "Timeout waiting for exception on other CPUs";
	default:
		sprintf(buf, "bank=%x", bank);
		return buf;
	}
}

void dump_intel_event(struct ras_events *ras,
		      struct trace_seq *s, struct mce_event *e)
{
	trace_seq_printf(s, "%s ",bank_name(e->bank));
	trace_seq_printf(s, ", mcgcap= %d ", e->mcgcap);
	trace_seq_printf(s, ", mcgstatus= %d ", e->mcgstatus);
	trace_seq_printf(s, ", status= %d ", e->status);
	trace_seq_printf(s, ", addr= %d ", e->addr);
	trace_seq_printf(s, ", misc= %d ", e->misc);
	trace_seq_printf(s, ", ip= %d ", e->ip);
	trace_seq_printf(s, ", tsc= %d ", e->tsc);
	trace_seq_printf(s, ", walltime= %d ", e->walltime);
	trace_seq_printf(s, ", cpu= %d ", e->cpu);
	trace_seq_printf(s, ", cpuid= %d ", e->cpuid);
	trace_seq_printf(s, ", apicid= %d ", e->apicid);
	trace_seq_printf(s, ", socketid= %d ", e->socketid);
	trace_seq_printf(s, ", cs= %d ", e->cs);
	trace_seq_printf(s, ", cpuvendor= %d", e->cpuvendor);
}

