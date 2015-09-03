/*
 * SocketConstants.h
 *
 *  Created on: Aug 27, 2015
 *      Author: jairo-mm
 */

#ifndef SOCKET_SOCKETCONSTANTS_H_
#define SOCKET_SOCKETCONSTANTS_H_

class SocketConstants {
public:
	SocketConstants();
	virtual ~SocketConstants();

	const bool DEBUGGEAR = true;
	const char* ERROR_AL_CREAR_SOCKET = "Error al intentar abrir el socket";
	const char* SE_HA_CREADO_EL_SOCKET = "Se ha creado el socket";
	const char* ERROR_EN_EL_BIND = "Error, falló el bind";
	const char* SE_LOGRO_EL_BIND = "Se logró unir";
	const char* FALLO_ACEPTAR_LA_CONEXION = "Error al aceptar";
	const char* FALLO_EN_LA_CONEXION = "No se logró establecer la conexion, FALLO";
	const char* SE_ESTABLECIO_UNA_CONEXION = "Se estableció una conexión con un cliente";
	const char* NO_SE_PUEDE_CREAR_THREAD = "No se pudo crear el thread";
	const char* MENSAJE_ENVIAR_A_CLIENTE = "Buenas yo sere tu manejador de conexion";
	const char* CLIENTE_DESCONECTADO = "Se ha desconectado el cliente";
	const char* ERROR_AL_RECIBIR_MENSAJE = "Error al recibir el mensaje";
	const char* ERROR_ENVIANDO_MENSAJE = "Error al enviar mensaje";
	const char* ERROR_NO_HAY_HOST = "Error no hay host";
	const char* ESCUCHANDO = "Escuchando";
	const char* ESPERANDO_CONEXIONES = "Esperando Conexiones";
	const char* ASIGNACION_DEL_MANEJADOR = "Se ha asignado el manejador";

};

#endif /* SOCKET_SOCKETCONSTANTS_H_ */
