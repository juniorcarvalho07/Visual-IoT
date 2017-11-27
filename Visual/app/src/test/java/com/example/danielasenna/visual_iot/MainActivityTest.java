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

    @Test
    public void testverificarValorSensorA2() throws Exception {
        boolean a = m.verificarValorSensorA(1);
        assertTrue(a);
    }

	@Test
    public void testverificarValorSensorA3() throws Exception {
        boolean a = m.verificarValorSensorA(4);
        assertFalse(a);
    }
	
	@Test
    public void testverificarValorSensorA4() throws Exception {
        boolean a = m.verificarValorSensorA((float) 0.5);
        assertTrue(a);
    }
	
	@Test
    public void testverificarValorSensorB1() throws Exception {
        boolean a = m.verificarValorSensorB(3);
        assertFalse(a);
    }
	
	@Test
    public void testverificarValorSensorB2() throws Exception {
        boolean a = m.verificarValorSensorB(1);
        assertTrue(a);
    }

}