An **Extended DNS Record Types Cheat Sheet** that provides an overview of various DNS record types, their purposes, and usage examples in table format.

---

## **1. Overview of DNS Record Types Table**

| **Record Type** | **Description**                                     | **Usage**                                       |
|------------------|-----------------------------------------------------|-------------------------------------------------|
| **A**            | Maps a domain name to an IPv4 address               | `example.com A 192.0.2.1`                       |
| **AAAA**         | Maps a domain name to an IPv6 address               | `example.com AAAA 2001:db8::1`                  |
| **CNAME**        | Canonical name record, aliases one domain to another| `www.example.com CNAME example.com`             |
| **MX**           | Mail exchange record, specifies mail servers        | `example.com MX 10 mail.example.com`            |
| **NS**           | Name server record, specifies authoritative DNS servers| `example.com NS ns1.example.com`              |
| **PTR**          | Pointer record, maps an IP address to a domain name | `1.2.0.192.in-addr.arpa PTR example.com`       |
| **SOA**          | Start of authority record, provides zone information | `example.com SOA ns1.example.com. admin.example.com. 2024102701 7200 3600 604800 86400` |
| **SRV**          | Service record, specifies services available         | `_sip._tcp.example.com SRV 10 60 5060 sipserver.example.com` |
| **TXT**          | Text record, holds arbitrary text data               | `example.com TXT "v=spf1 include:_spf.example.com ~all"` |
| **SPF**          | Sender Policy Framework record, for email validation  | `example.com TXT "v=spf1 mx -all"`             |

---

## **2. Detailed DNS Record Types Table**

| **Record Type** | **Name**            | **Description**                                         | **Example**                                         |
|------------------|---------------------|---------------------------------------------------------|-----------------------------------------------------|
| **A**            | Address Record      | Maps domain to IPv4 address                             | `example.com A 192.0.2.1`                           |
| **AAAA**         | IPv6 Address Record | Maps domain to IPv6 address                             | `example.com AAAA 2001:db8::1`                      |
| **CNAME**        | Canonical Name      | Aliases one domain to another                           | `www.example.com CNAME example.com`                 |
| **MX**           | Mail Exchange       | Specifies mail servers for domain                       | `example.com MX 10 mail.example.com`                |
| **NS**           | Name Server         | Indicates DNS servers authoritative for the domain     | `example.com NS ns1.example.com`                    |
| **PTR**          | Pointer             | Maps IP address to domain name                          | `1.2.0.192.in-addr.arpa PTR example.com`            |
| **SOA**          | Start of Authority  | Contains metadata about the domain's DNS zone          | `example.com SOA ns1.example.com. admin.example.com. 2024102701 7200 3600 604800 86400` |
| **SRV**          | Service             | Specifies services available for the domain            | `_sip._tcp.example.com SRV 10 60 5060 sipserver.example.com` |
| **TXT**          | Text                | Holds arbitrary text data                               | `example.com TXT "v=spf1 include:_spf.example.com ~all"` |
| **SPF**          | Sender Policy Framework | Specifies allowed mail servers for domain             | `example.com TXT "v=spf1 mx -all"`                  |

---

## **3. Usage Details Table**

| **Record Type** | **Usage Scenario**                                      | **Additional Notes**                                    |
|------------------|--------------------------------------------------------|---------------------------------------------------------|
| **A**            | Pointing domain to web servers                          | Essential for routing traffic to the server             |
| **AAAA**         | Pointing domain to IPv6-enabled web servers            | Important for modern networks supporting IPv6            |
| **CNAME**        | Redirecting subdomains to main domain                   | Useful for maintaining multiple aliases                  |
| **MX**           | Configuring email delivery for the domain               | Multiple MX records can be used for redundancy           |
| **NS**           | Delegating authority to other DNS servers               | Defines which servers should be queried for domain info  |
| **PTR**          | Reverse DNS lookup for IP addresses                     | Often used for verifying domain ownership                |
| **SOA**          | Defining the primary DNS server for the domain         | Contains essential info like serial number and refresh times |
| **SRV**          | Specifying location of services (e.g., VoIP)           | Allows clients to discover services via DNS              |
| **TXT**          | Providing additional information for validation          | Commonly used for SPF, DKIM, or other service configurations |
| **SPF**          | Specifying which IP addresses are allowed to send mail  | Helps in preventing email spoofing                        |

---

## **4. Example DNS Records Table**

| **Record**                                   | **Record Type** | **Details**                                            |
|----------------------------------------------|------------------|-------------------------------------------------------|
| `example.com A 192.0.2.1`                   | A                | Points `example.com` to an IPv4 address              |
| `example.com AAAA 2001:db8::1`               | AAAA             | Points `example.com` to an IPv6 address               |
| `www.example.com CNAME example.com`          | CNAME            | Redirects `www.example.com` to `example.com`         |
| `example.com MX 10 mail.example.com`         | MX               | Directs mail to `mail.example.com` with priority 10   |
| `example.com NS ns1.example.com`             | NS               | Indicates `ns1.example.com` is the authoritative DNS  |
| `1.2.0.192.in-addr.arpa PTR example.com`     | PTR              | Maps the IP `192.0.2.1` to `example.com`             |
| `example.com SOA ns1.example.com. admin@example.com. 2024102701 7200 3600 604800 86400` | SOA | Contains zone configuration information                |
| `_sip._tcp.example.com SRV 10 60 5060 sipserver.example.com` | SRV | Specifies SIP service details                          |
| `example.com TXT "v=spf1 include:_spf.example.com ~all"` | TXT | SPF record for email validation                        |
| `example.com TXT "v=spf1 mx -all"`          | SPF              | SPF record specifying mail server permissions          |

---

## **5. Common DNS Record Commands (Using `dig`) Table**

| **Command**                                   | **Description**                              | **Example Output**                       |
|-----------------------------------------------|----------------------------------------------|------------------------------------------|
| `dig example.com A`                           | Query the A record for a domain            | Shows the IPv4 address for `example.com` |
| `dig example.com AAAA`                        | Query the AAAA record for a domain         | Shows the IPv6 address for `example.com` |
| `dig example.com MX`                          | Query the MX records for a domain          | Lists mail servers for `example.com`     |
| `dig example.com NS`                          | Query the NS records for a domain          | Lists authoritative name servers          |
| `dig -x 192.0.2.1`                            | Perform a reverse DNS lookup                | Shows the domain associated with the IP    |
| `dig example.com TXT`                         | Query the TXT records for a domain         | Displays any TXT records for `example.com` |
| `dig example.com SOA`                         | Query the SOA record for a domain          | Shows zone information                     |
| `dig @ns1.example.com example.com`           | Query specific name server                  | Gets records from `ns1.example.com`       |

---

This cheat sheet provides a comprehensive overview of **DNS Record Types**.
