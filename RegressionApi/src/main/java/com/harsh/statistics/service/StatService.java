package com.harsh.statistics.service;

import java.util.Vector;

import org.springframework.stereotype.Service;

import com.harsh.statistics.model.Data;
import com.harsh.statistics.model.Stats;
@Service
public class StatService {
	
	public Stats getAll(Data data) {
		// TODO Auto-generated method stub
		if(data.getDx().size()!=data.getDy().size()) {
			return null;
		}
		Double sum=(double) 0;
		Stats s = new Stats();
		Vector<Double> dx= data.getDx();
		for(int i=0;i<dx.size();i++) {
			System.out.println(dx.get(i));
			sum=sum+dx.get(i);
		}
		s.setSumX(sum);
		s.setXmean(sum/dx.size());
		sum=(double) 0;
		Vector<Double> dy= data.getDy();
		for(int i=0;i<dy.size();i++) {
			System.out.println(dy.get(i));
			sum=sum+dy.get(i);
		}
		s.setSumY(sum);
		s.setYmean(sum/dy.size());
		
		Double xmxb=(double) 0,ymyb=(double) 0,xmxymyb=(double) 0,xmxb2=(double) 0,ymyb2=(double) 0;
		for(int i=0;i<dx.size();i++) {
			xmxb= xmxb+(dx.get(i)-s.getXmean());
			ymyb= ymyb+(dy.get(i)-s.getYmean());
			xmxymyb=xmxymyb+(xmxb*ymyb);
			xmxb2=xmxb2+(Math.pow(xmxb, 2));
			ymyb2=ymyb2+(Math.pow(ymyb, 2));
		}
		Double m=(xmxymyb)/xmxb2;
		Double y=s.getYmean()-(m*s.getXmean());
		m=Math.round(m*100D)/100D;
		s.setSlope(m);
		y=Math.round(y*100D)/100D;
		s.setIntercept(y);
		s.setEquation("y = "+m+"x + "+y);
		Double r = xmxymyb/Math.sqrt(xmxb2*ymyb2);
		r=Math.round(r*100D)/100D;
		s.setCorrelation(r);
		if(r<0.05) {
			s.setCorrelationRemarks("Negative Correlation seen");
		}else if(r<=0.05&&r>=-0.05){
			s.setCorrelationRemarks("Almost No Correlation seen");
		}else {
			s.setCorrelationRemarks("Positive Correlation seen");
		}
		return s;
	}

}
