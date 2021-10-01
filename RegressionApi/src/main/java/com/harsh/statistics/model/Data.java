package com.harsh.statistics.model;

import java.util.Vector;
public class Data {
	private Vector<Double> dx;
	private Vector<Double> dy;
	public Data(Vector<Double> dx, Vector<Double> dy) {
		super();
		this.dx = dx;
		this.dy = dy;
	}
	public Vector<Double> getDx() {
		return dx;
	}
	public void setDx(Vector<Double> dx) {
		this.dx = dx;
	}
	public Vector<Double> getDy() {
		return dy;
	}
	public void setDy(Vector<Double> dy) {
		this.dy = dy;
	}
	
}
