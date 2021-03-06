/*
Copyright (c) 2001-2006, Gerrit Pape
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
   3. The name of the author may not be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "busybox.h"

int get_uidgid(struct bb_uidgid_t *u, const char *ug, int numeric_ok)
{
	struct passwd *pwd;
	struct group *gr;
	char *user, *group;
	unsigned n;

	user = (char*)ug;
	group = strchr(ug, ':');
	if (group) {
		int sz = (++group) - ug;
		user = alloca(sz);
		/* copies sz-1 bytes, stores terminating '\0' */
		safe_strncpy(user, ug, sz);
	}
	if (numeric_ok) {
		n = bb_strtou(user, NULL, 10);
		if (!errno) {
			u->uid = n;
			pwd = getpwuid(n);
			/* If we have e.g. "500" string without user */
			/* with uid 500 in /etc/passwd, we set gid == uid */
			u->gid = pwd ? pwd->pw_gid : n;
			goto skip;
		}
	}
	pwd = getpwnam(user);
	if (!pwd)
		return 0;
	u->uid = pwd->pw_uid;
	u->gid = pwd->pw_gid;

 skip:
	if (group) {
		if (numeric_ok) {
			n = bb_strtou(group, NULL, 10);
			if (!errno) {
				u->gid = n;
				return 1;
			}
		}
		gr = getgrnam(group);
		if (!gr) return 0;
		u->gid = gr->gr_gid;
	}
	return 1;
}

#if 0
#include <stdio.h>
int main()
{
	unsigned u;
	struct bb_uidgid_t ug;
	u = get_uidgid(&ug, "apache", 0);
	printf("%u = %u:%u\n", u, ug.uid, ug.gid);
	ug.uid = ug.gid = 1111;
	u = get_uidgid(&ug, "apache", 0);
	printf("%u = %u:%u\n", u, ug.uid, ug.gid);
	ug.uid = ug.gid = 1111;
	u = get_uidgid(&ug, "apache:users", 0);
	printf("%u = %u:%u\n", u, ug.uid, ug.gid);
	ug.uid = ug.gid = 1111;
	u = get_uidgid(&ug, "apache:users", 0);
	printf("%u = %u:%u\n", u, ug.uid, ug.gid);
	return 0;
}
#endif
