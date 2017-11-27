package com.example.danielasenna.visualiot;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Daniela Senna on 26/11/2017.
 */
public class MainActivityTest {

    MainActivity m = new MainActivity();

   
    @Test
    public void testverificarValorSensorA1() throws Exception {
        boolean a = m.verificarValorSensorA(3);
        assertFalse(a);
    }

    



}