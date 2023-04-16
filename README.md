PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central del grupo):
	-	Acceda la página de la [Práctica 2](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.

	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual, usando el repositorio remoto en GitHub como repositorio central para el trabajo colaborativo
	de los distintos miembros del grupo de prácticas o como copia de seguridad.
	-	Puede *confirmar* versiones del proyecto en su directorio local con las órdenes siguientes:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

	-	Las versiones confirmadas, y sólo ellas, se almacenan en el repositorio y pueden ser accedidas en cualquier momento.

*	Para interactuar con el contenido remoto en GitHub es necesario que los cambios en el directorio local estén confirmados.

	-	Puede comprobar si el directorio está *limpio* (es decir, si la versión actual está confirmada) usando el comando
		`git status`.

	-	La versión actual del directorio local se sube al repositorio remoto con la orden:

		```.sh
		git push
		```

		*	Si el repositorio remoto contiene cambios no presentes en el directorio local, `git` puede negarse
			a subir el nuevo contenido.

			-	En ese caso, lo primero que deberemos hacer es incorporar los cambios presentes en el repositorio
				GitHub con la orden `git pull`.

			-	Es posible que, al hacer el `git pull` aparezcan *conflictos*; es decir, ficheros que se han modificado
				tanto en el directorio local como en el repositorio GitHub y que `git` no sabe cómo combinar.

			-	Los conflictos aparecen marcados con cadenas del estilo `>>>>`, `<<<<` y `====`. Los ficheros correspondientes
				deben ser editados para decidir qué versión preferimos conservar. Un editor avanzado, del estilo de Microsoft
				Visual Studio Code, puede resultar muy útil para localizar los conflictos y resolverlos.

			-	Tras resolver los conflictos, se ha de confirmar los cambios con `git commit` y ya estaremos en condiciones
				de subir la nueva versión a GitHub con el comando `git push`.


	-	Para bajar al directorio local el contenido del repositorio GitHub hay que ejecutar la orden:

		```.sh
		git pull
		```
	
		*	Si el repositorio local contiene cambios no presentes en el directorio remoto, `git` puede negarse a bajar
			el contenido de este último.

			-	La resolución de los posibles conflictos se realiza como se explica más arriba para
				la subida del contenido local con el comando `git push`.



*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los
elementos más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.
  
  >![Captura de Pantalla 2023-04-05 a las 13 45 22](https://user-images.githubusercontent.com/125216138/230577406-738fe232-97f4-4fe5-aa67-4a1b57841842.png)
  >
  >Podemos observar en la imagen el contorno de la potencia en la parte superior, seguida de la tasa de cruces por cero (ZCR), obtenida con el 
  código de la primera práctica. El tercer panel representa el etiquetado manual de las secciones de voz y silencio, y finalmente en la parte 
  inferior tenemos la señal original en el dominio temporal.


- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para
	  estar seguros de que un segmento de señal se corresponde con voz.
	  
	  >Hemos utilizado el audio Nueva-grabación-2.wav. El silencio corresponde aproximadamente a 15-20 dB y cuando aparece la señal de voz la potencia sube a unos 50 dB, es decir, de silencio a voz incrementa unos 30 dB. Además, hay que tener en cuenta que un sonido sonoro tiene más potencia que un sonido sordo.

	* Duración mínima razonable de los segmentos de voz y silencio.
	  
	  >Los segmentos de voz suelen ser variables, dependiendo de las frases o palabras que se pronuncien. En nuestra grabación, la duración mínima de un segmento de voz está en los 0.3 segundos y puede llegar hasta 1.3 segundos. Los segmentos de silencio pueden durar de 0.5 segundos hasta 1 segundo.

	* ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?
	
	  >Gracias a la tasa de cruces por cero (ZCR) podemos detectar a los sonidos sordos ya que tienen una tasa mucho más elevada 
	  que los sonoros. También la tasa incrementa cuando hay silencios.


### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal en
  tiempo real tan exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.

  >A partir de ahora, para el resto de la práctica, el fichero de audio que hemos utilizado es el de prueb.wav.
  >
  >Despues de probar varios valores para los parámetros, hemos llegado a la conclusión de que obteníamos resultados más precisos con los siguientes:
  ```
  alpha1 = 7.5
  alpha2 = 3.5
  t_voice = 0
  t_silence = 0.12
  zcr_v = 3800
  zcr_s = 3400
  ```
  
  >Tras completar el código implementando los cuatro estados y con los parámetros mencionados anteriormente, hemos conseguido una precisión de 92.876% y en el conjunto de señales de la base de datos un F-score de 93.012%. 
  >
  >Lo podemos comprobar en las siguientes capturas de la ejecución del programa:
  >
  >![WhatsApp Image 2023-04-16 at 19 35 39](https://user-images.githubusercontent.com/125216138/232331773-9b367b96-0b91-4f55-88b1-630688fd19c7.jpeg)
  >
  >![WhatsApp Image 2023-04-16 at 19 35 38](https://user-images.githubusercontent.com/125216138/232331779-254846d6-87f5-4bc6-b413-2578927b9477.jpeg)


- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 
  
  >![Captura de Pantalla 2023-04-16 a las 20 42 25](https://user-images.githubusercontent.com/125216138/232334668-a05efcbb-becd-45c3-86fe-86ac773dcbf7.png)

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.

  > Como podemos observar en la imagen de la pregunta anterior, hay una pequeña diferencia entre el etiquetado manual y la detección automática. En la detección automática clasifica una trama como silencio y otra pequeña trama como voz, a diferencia del etiquetado manual donde los incluimos en una única trama. A pesar de esto, la detección automática es muy acertada.

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).
  >Como hemos comentado en el primer ejercicio, el mejor resultado que hemos conseguido ha sido el siguiente: 
  >
  >![WhatsApp Image 2023-04-16 at 19 35 38](https://user-images.githubusercontent.com/125216138/232331779-254846d6-87f5-4bc6-b413-2578927b9477.jpeg)


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).
  
  >A continuación encontramos la señal original y la señal después de la cancelación:
  >
  ><img width="49%" alt="WhatsApp Image 2023-04-16 at 18 28 52" src=https://user-images.githubusercontent.com/125216138/232327099-b451a970-5d81-4c19-bb1d-17b0ef7f3c9d.jpeg>  <img width="49%" alt="WhatsApp Image 2023-04-16 at 18 28 52 (1)" src=https://user-images.githubusercontent.com/125216138/232327106-94d40d0a-c207-43ba-8f12-b18c9fc9771b.jpeg>
  >
  > Observando las dos gráficas, podemos concluir que funciona perfectamente ya que la señal de voz ha sido perfectamente modificada para añadir ceros en las tramas detectadas como silencios

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.
  
  ```
  VAD - Voice Activity Detector

  Usage:
     vad [options] -i <input-wav> -o <output-vad> [-w <output-wav>]
     vad (-h | --help)
     vad --version

  Options:
     -i FILE, --input-wav=FILE   WAVE file for voice activity detection
     -o FILE, --output-vad=FILE  Label file with the result of VAD
     -w FILE, --output-wav=FILE  WAVE file with silences cleared
     -1 FILE, --alfa1=FLOAT      Marge sobre k0 per determinar el llindar d'un V/S [default: 7.5]
     -2 FILE, --alfa2=FLOAT      Marge sobre P1 per determinar el llindar d'un V/S [default: 3.5]
     -V FILE, --t_voice=FLOAT    Temps mínim per considerar veu [default: 0]
     -S FILE, --t_silence=FLOAT  Temps mínim per considerar vsilencia [default: 0.12]
     -zs FILE, --zcr_s=FLOAT        LLindar ZCR silenci [default: 3400]
     -zv FILE, --zcr_v=FLOAT        LLindar ZCR veu [default: 3800]
     -v, --verbose  Show debug information
     -h, --help     Show this screen
     --version      Show the version of the project
  ```

### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que
  considere de interés de cara a su evaluación.


### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.
