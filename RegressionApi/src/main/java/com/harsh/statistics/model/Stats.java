package com.harsh.statistics.model;

public class Stats {
	private Double sumX,sumY;
	private Double xmean,ymean;
	private String equation;
	private Double slope,intercept;
	private Double correlation;
	private String correlationRemarks;
	public String getCorrelationRemarks() {
		return correlationRemarks;
	}
	public void setCorrelationRemarks(String correlationRemarks) {
		this.correlationRemarks = correlationRemarks;
	}
	public Double getSumX() {
		return sumX;
	}
	public void setSumX(Double sumX) {
		this.sumX = sumX;
	}
	public Double getSumY() {
		return sumY;
	}
	public void setSumY(Double sumY) {
		this.sumY = sumY;
	}
	public Double getCorrelation() {
		return correlation;
	}
	public void setCorrelation(Double correlation) {
		this.correlation = correlation;
	}
	public Double getXmean() {
		return xmean;
	}
	public void setXmean(Double xmean) {
		this.xmean = xmean;
	}
	public Double getYmean() {
		return ymean;
	}
	public void setYmean(Double ymean) {
		this.ymean = ymean;
	}
	public String getEquation() {
		return equation;
	}
	public void setEquation(String equation) {
		this.equation = equation;
	}
	public Double getSlope() {
		return slope;
	}
	public void setSlope(Double slope) {
		this.slope = slope;
	}
	public Double getIntercept() {
		return intercept;
	}
	public void setIntercept(Double intercept) {
		this.intercept = intercept;
	}
	
}
