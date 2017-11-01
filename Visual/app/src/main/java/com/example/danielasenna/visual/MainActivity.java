package com.example.danielasenna.visual;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.Toast;

import java.util.UUID;

/**
 * Created by Daniela Senna on 27/10/2017.
 */

public class MainActivity extends AppCompatActivity {

    //Button desconectar, conectar, conect, led;

    Button conect, led;

    BluetoothAdapter meuBluetooth = null;
    BluetoothDevice meuDevice = null;
    BluetoothSocket meuSocket = null;

    UUID MEU_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");

    private static final int ATIVA_BLUETOOH = 1; // Esse valor sera utilizado durante o processo de ativação do Bluetooth
    private static final int ATIVA_CONEXAO = 2; // Esse valor sera utilizado durante o processo de conexão com um dispositivo pareado


    boolean conexao = false;


    private static String Mac = null;


    @Override
    protected void onPause(){
        super.onPause();
        Toast.makeText(this, "Pausa", Toast.LENGTH_SHORT).show();

    }

    @Override
    protected void onDestroy(){
        super.onDestroy();
        meuBluetooth.disable();
    }


    // Essa clase verifica se o aparelho possui Bluetooth
    // E verifica se o Bluetooh está ativo, caso não esteja ativado, envia uma solicitação para que o usuario ative
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);



        // Antes de tentar buscar ou conectar a outros dispositivos,
        // é importante garantir que o aplicativo está sendo executado
        // em um aparelho que suporta a funcionalidade Bluetooth e
        // cujo hardware está em pleno funcionamento.

        // Para utilizar qualquer recurso Bluetooth na nossa aplicação,
        // precisamos da instância da classe BluetoothAdapter, que pode
        // ser obtida através do método estático getDefaultAdapter()

        meuBluetooth = BluetoothAdapter.getDefaultAdapter();

        // Depois de obter a instância da classe Bluetooth verifica-se o aparelho tem suporte a Bluetooth.
        // Se o valor de retorno da instância for igual a null, quer dizer que o aparelho não tem suporte a Bluetooth.
        if(meuBluetooth == null){
            Toast.makeText(getApplicationContext(), "Seu dispositivo não possui Bluetooth", Toast.LENGTH_LONG).show();
        }else{

            if(!meuBluetooth.isEnabled()){
                meuBluetooth.enable(); // Ativa automaticamente o Bluetooth
                Toast.makeText(getApplicationContext(), "Bluetooth Ativado", Toast.LENGTH_LONG).show();
            }else{
                Toast.makeText(getApplicationContext(), "O Bluetooth já está Ativado", Toast.LENGTH_LONG).show();
            }

            //meuBluetooth.disable(); // Desativa automaticamente o Bluettoth

            // Depois de obter a instância e caso não seja null
            // é necessário checar se o aparelho está com o Bluetooth ativado.

            // O código a baixo verifica se o Bluetooth está ativado.
            // Se não, envia uma solicitação ao sistema na forma de um Intent para que o ative.
            // Caso o Bluetooth já esteja ativado, você pode ficar tranquilo.

        }

    }

    //Essa clase permite saber se o usuario ativou ou nao o Bluetooth
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        //super.onActivityResult(requestCode, resultCode, data);

        switch(requestCode){
            case ATIVA_BLUETOOH:

                // retornando um resultado. Esse valor é definido na chamada do método
                // startActivityForResult(). Veja o valor ENABLE_BLUETOOTH.
                // É um inteiro. Com isso, podemos saber qual Activity está retornando o resultado.

                // resultCode: traz a informação sobre a decisão do usuário.
                // RESULT_OK, nesse caso, significa que o adaptador Bluetooth
                // foi ativado, qualquer outro valor significa que o usuário
                // negou a permissão ou que um erro ocorreu.
                if(resultCode == Activity.RESULT_OK){
                    Toast.makeText(getApplicationContext(), "Bluetooth Ativado", Toast.LENGTH_LONG).show();
                }else{
                    Toast.makeText(getApplicationContext(), "Bluetooth Desativado, O App será Encerrado", Toast.LENGTH_LONG).show();
                    finish();
                }
                break;

            case ATIVA_CONEXAO:
                break;

        }
    }
}
