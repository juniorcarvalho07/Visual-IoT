package com.example.danielasenna.visual_iot;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {



    static TextView status;
    static TextView m1;
    static TextView m2;
    static TextView m3;
	
	ConnectionThread connect;
	
	static Activity a;
	

    // Esse método verifica se o aparelho possui Bluetooth e se o mesmo esta ativado
    // Caso não esteja ativado, o Bluetooth é ativado

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        /* Link entre os elementos da interface gráfica e suas
            representações em Java.
         */
        status = (TextView) findViewById(R.id.sens);
        m1 = (TextView) findViewById(R.id.m1);
        m2 = (TextView) findViewById(R.id.m2);
        m3 = (TextView) findViewById(R.id.m3);

		// Definição de uma Activity alternativa
		Activity a1 = this;
		a = a1;

	
        // Antes de tentar buscar ou conectar a outros dispositivos,
        // é importante garantir que o aplicativo está sendo executado
        // em um aparelho que suporta a funcionalidade Bluetooth e
        // cujo hardware está em pleno funcionamento.

        // Para utilizar qualquer recurso Bluetooth na nossa aplicação,
        // precisamos da instância da classe BluetoothAdapter, que pode
        // ser obtida através do método estático getDefaultAdapter()

        BluetoothAdapter btAdapter = BluetoothAdapter.getDefaultAdapter();


        // Depois de obter a instância da classe Bluetooth verifica-se o aparelho tem suporte a Bluetooth.
        // Se o valor de retorno da instância for igual a null, quer dizer que o aparelho não tem suporte a Bluetooth.
        if(btAdapter == null){
            Toast.makeText(getApplicationContext(), "Seu disposit ivo não possui Bluetooth", Toast.LENGTH_LONG).show();
        }else {
            // Depois de obter a instância e caso não seja null
            // é necessário checar se o aparelho está com o Bluetooth ativado.

            // O código a baixo verifica se o Bluetooth está ativado.
            // Se não, envia uma solicitação ao sistema na forma de um Intent para que o ative.
            // Caso o Bluetooth já esteja ativado, você pode ficar tranquilo.

            if (!btAdapter.isEnabled()) {
                btAdapter.enable(); // Ativa automaticamente o Bluetooth
                Toast.makeText(getApplicationContext(), "Bluetooth Ativado", Toast.LENGTH_LONG).show();
            } else {
                Toast.makeText(getApplicationContext(), "O Bluetooth já está Ativado", Toast.LENGTH_LONG).show();
            }
        }

        /* A chamada do seguinte método liga o Bluetooth no dispositivo Android
            sem pedido de autorização do usuário. É altamente não recomendado no
            Android Developers.
         */
		
		/* Definição da thread de conexão como cliente.
        Aqui, você deve incluir o endereço MAC do seu módulo Bluetooth.
        O app iniciará e vai automaticamente buscar por esse endereço.
        Caso não encontre, dirá que houve um erro de conexão.
		 */
		connect = new ConnectionThread("98:D3:36:00:9D:51");
		connect.start();

		/* Um descanso rápido, para evitar bugs esquisitos.
		 */
		try {
			Thread.sleep(1000);
		} catch (Exception E) {
			E.printStackTrace();
		}

    }


}