import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { environment } from 'src/environments/environment';
import {Customer} from './customer'
@Injectable({
  providedIn: 'root'
})
export class CustomerService {
  private apiServerUrl = environment.apiBaseUrl;
  constructor(private http:HttpClient) { }
  public getEmployees(): Observable<Customer[]> {
    return this.http.get<Customer[]>(`${this.apiServerUrl}/customer/all`);
  }
  public getEmployee(customerId:number): Observable<Customer>{
    return this.http.get<Customer>(`${this.apiServerUrl}/customer/find/${customerId}`);
  }
  public addEmployee(customer: Customer): Observable<Customer> {
    return this.http.post<Customer>(`${this.apiServerUrl}/customer/add`, customer);
  }

  public updateEmployee(customer: Customer): Observable<Customer> {
    return this.http.put<Customer>(`${this.apiServerUrl}/customer/update`, customer);
  }

  public deleteEmployee(employeeId: number): Observable<void> {
    return this.http.delete<void>(`${this.apiServerUrl}/customer/delete/${employeeId}`);
  }
}
