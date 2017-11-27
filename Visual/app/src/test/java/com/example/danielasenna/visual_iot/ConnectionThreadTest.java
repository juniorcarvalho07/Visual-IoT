package com.example.danielasenna.visualiot;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Daniela Senna on 26/11/2017.
 */
public class ConnectionThreadTest {
    ConnectionThread c = new ConnectionThread();

    @Test
    public void connection() throws Exception {
        boolean a = c.server;

        assertTrue(a);
    }

   @Test
    public void cancel() throws Exception {
        boolean a = c.isConnected;
        boolean b = c.running;

        assertFalse(a);
        assertFalse(b);
    }
	
	@Test
    public void isConnected() throws Exception {
        boolean a = c.isConnected;

        assertFalse(a);
    }
}