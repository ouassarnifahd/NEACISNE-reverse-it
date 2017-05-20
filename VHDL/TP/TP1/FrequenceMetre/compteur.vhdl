library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: compteur --

entity compteur is
    port ( clk : in STD_LOGIC;
           valid : in STD_LOGIC;
           raz : in STD_LOGIC;
           TTL_mef : in STD_LOGIC;
           freq : out STD_LOGIC_VECTOR(15 downto 0));
end compteur;

architecture behavioral of compteur is
    signal u,d,c,m : STD_LOGIC_VECTOR(3 downto 0) := "0000";
    signal Flag : STD_LOGIC := '0';

begin

SYNC : process(clk)
begin
    if rising_edge(clk) then
        if raz='1' then
            u <= "0000";
            d <= "0000";
            c <= "0000";
            m <= "0000";
            Flag <= '0';
        elsif (valid='1' and TTL_mef='1' and Flag='0') then
            if u="1001" then
                u <= "0000";
                if d="1001" then
                    d <= "0000";
                    if c="1001" then
                        c <= "0000";
                        if m="1001" then
                            Flag <= '1';
                        else
                            m <= m+1;
                        end if;
                    else
                        c <= c+1;
                    end if;
                else
                    d <= d+1;
                end if;
            else
                u <= u+1;
            end if;
        end if;
    end if;
end process;

freq <= m&c&d&u when Flag='0' else X"0000";

end behavioral;
