/*
 * IRC - Internet Relay Chat, include/s_bdd.h
 * Copyright (C) 1999 IRC-Hispano.org - ESNET - jcea & savage
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(S_BDD_H)
#define S_BDD_H

#include "struct.h"

#define ESNET_BDD         'a'
#define ESNET_BDD_END     'z'
#define ESNET_NICKDB      'n'
#define ESNET_CLONESDB    'i'

#define BDD_OPERDB        'o'
#define BDD_BOTSDB        'b'
#define BDD_CHANDB        'c'
#define BDD_IPVIRTUALDB   'v'
#define BDD_IPVIRTUAL2DB  'w'
#define BDD_CHANDB_OLD    'z'
#define BDD_CONFIGDB      'z'

/*
** Registros de configuracion en la tabla 'z'
*/
#define BDD_NUMERO_MAXIMO_DE_CLONES_POR_DEFECTO	"numero.maximo.de.clones.por.defecto"
#define BDD_MENSAJE_DE_DEMASIADOS_CLONES	"mensaje.de.demasiados.clones"
#define BDD_MENSAJE_DE_CAPACIDAD_SUPERADA	"mensaje.de.capacidad.superada"
#define BDD_CLAVE_DE_CIFRADO_DE_IPS		"clave.de.cifrado.de.ips"
#define BDD_OCULTAR_IP_CIFRADA_EN_LA_VIRTUAL2	"ocultar.ip.cifrada.en.la.virtual2"
#define BDD_OCULTAR_SERVIDORES_EN_EL_MAP	"ocultar.servidores.en.el.map"
#define BDD_DOMINIO_DE_LA_RED			"dominio.de.la.red"
#define BDD_NOMBRE_DE_LA_RED			"nombre.de.la.red"
#define BDD_DESCRIPCION_SERVIDORES		"descripcion.servidores"
#define BDD_BOT_VIRTUAL_NICKSERV		"bot.virtual.nickserv"
#define BDD_BOT_VIRTUAL_CHANSERV		"bot.virtual.chanserv"
#define BDD_FINAL_IPVIRTUAL_UBOT		"final.ipvirtual.ubot"

struct db_reg {
  char *clave;
  char *valor;
  struct db_reg *next;
};

void reload_db(void);
void initdb(void);
struct DB_nick *find_db_nick(char *nick);
void tx_num_serie_dbs(aClient *cptr);
int m_db(aClient *cptr, aClient *sptr, int parc, char *parv[]);

void tea(unsigned int v[], unsigned int k[], unsigned int x[]);
struct db_reg *db_buscar_registro(unsigned char tabla, char *clave);
int db_es_miembro(unsigned char tabla, char *clave, char *subcadena);
int db_es_residente(unsigned char tabla);
unsigned int db_num_serie(unsigned char tabla);
unsigned int db_cuantos(unsigned char tabla);
struct db_reg *db_iterador_init(unsigned char tabla);
struct db_reg *db_iterador_next(void);

#if defined(BDD_MMAP)
int db_persistent_hit(void);
void db_persistent_commit(void);
#endif

int m_dbq(aClient *cptr, aClient *sptr, int parc, char *parv[]);

extern int ocultar_ip_cifrada_en_la_virtual2;
extern int ocultar_servidores_en_el_map;
extern int numero_maximo_de_clones_por_defecto;
extern char *dominio_de_la_red;
extern char *nombre_de_la_red;
extern char *descripcion_servidores;
extern char *clave_de_cifrado_de_ips;
extern unsigned int clave_de_cifrado_binaria[2];
extern char *bot_virtual_nickserv;
extern char *bot_virtual_chanserv;
extern char *final_ipvirtual_ubot;

/* -- mman.h no contiene algunas definicieones en plataformas antiguas -- */
#if !defined(MAP_FAILED)
#define MAP_FAILED ((void *) -1)
#endif
#if !defined(MAP_NORESERVE)
#define MAP_NORESERVE 0
#endif
/* -- savage 1999/11/19 -- */

#endif /* S_BDD_H */
